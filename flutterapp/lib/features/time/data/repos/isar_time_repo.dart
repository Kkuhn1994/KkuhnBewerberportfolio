import 'package:handwerksapp/features/time/data/isar_workday.dart';
import 'package:handwerksapp/features/time/data/time_repo.dart';
import 'package:handwerksapp/features/time/timespan_model.dart';
import 'package:handwerksapp/features/time/work_day_model.dart';
import 'package:isar/isar.dart';

class IsarTimeRepo implements TimeRepo {
  final Isar db;

  IsarTimeRepo({required this.db});

  @override
  Future<List<WorkDay>> getWorkDays() async {
    final timeIsar = await db.isarWorkdays.where().findAll();
    return timeIsar.map((time) => time.toDomain()).toList();
  }

  @override
  Future<void> startTime() async {
    List<WorkDay> listWorkDays = await getWorkDays();

    DateTime now = DateTime.now();
    Timespan newTime = Timespan(
        id: DateTime.now().microsecondsSinceEpoch,
        start: now,
        end: now,
        type: '"work');

    if (checkForDate(now, listWorkDays)) {
      listWorkDays.last.workAndBreakTimes.add(newTime);
      return db.writeTxn(
          () => db.isarWorkdays.put(IsarWorkday.fromDomain(listWorkDays.last)));
    }

    List<Timespan> newList = [];
    newList.add(newTime);
    return db.writeTxn(() => db.isarWorkdays.put(IsarWorkday.fromDomain(WorkDay(
        id: DateTime.now().microsecondsSinceEpoch,
        date: "${now.day}.${now.month}.${now.year}",
        workAndBreakTimes: newList))));
  }

  bool checkForDate(DateTime time, List<WorkDay> listDay) {
    if (listDay.isEmpty) {
      return false;
    }
    WorkDay lastDay = listDay.last;
    if (lastDay.date == "${time.day}.${time.month}.${time.year}") {
      return true;
    }
    return false;
  }

  Future<void> stopTime() async {
    List<WorkDay> listWorkDays = await getWorkDays();
    List<Timespan> listTimes = listWorkDays.last.workAndBreakTimes;
    listTimes[listTimes.length - 1] = listTimes[listTimes.length - 1].copyWith(
      end: DateTime.now(),
    );
    listWorkDays.last = listWorkDays.last.copyWith(
      workAndBreakTimes: listTimes,
    );
    return db.writeTxn(
        () => db.isarWorkdays.put(IsarWorkday.fromDomain(listWorkDays.last)));
  }

  @override
  Future<void> changeStartTime(Timespan time, WorkDay dayToChange) {
    int index = dayToChange.workAndBreakTimes
        .indexWhere((element) => element.id == time.id);
    dayToChange.workAndBreakTimes[index] = time;
    return db.writeTxn(
        () => db.isarWorkdays.put(IsarWorkday.fromDomain(dayToChange)));
  }

  @override
  Future<void> changeStopTime(Timespan time, WorkDay dayToChange) async {
    int index = dayToChange.workAndBreakTimes
        .indexWhere((element) => element.id == time.id);
    dayToChange.workAndBreakTimes[index] = time;
    print(dayToChange.workAndBreakTimes[index].end);
    return db.writeTxn(
        () => db.isarWorkdays.put(IsarWorkday.fromDomain(dayToChange)));
  }
}
