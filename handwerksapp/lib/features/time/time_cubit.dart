import 'package:flutter_bloc/flutter_bloc.dart';
import 'package:handwerksapp/features/time/data/time_repo.dart';
import 'package:handwerksapp/features/time/timespan_model.dart';
import 'package:handwerksapp/features/time/work_day_model.dart';

class TimeCubit extends Cubit<List<WorkDay>> {
  final TimeRepo timeRepo;

  int newState = 0;
  TimeCubit(this.timeRepo) : super([]);

  Future<void> loadState() async {
    List<WorkDay> times = await timeRepo.getWorkDays();
    emit(times);
  }

  Future<void> startTime() async {
    await timeRepo.startTime();
    await loadState();
  }

  Future<void> stopTime() async {
    await timeRepo.stopTime();
    await loadState();
  }

  Future<void> changeStartTime(Timespan time, WorkDay dayToChange) async {
    await timeRepo.changeStartTime(time, dayToChange);
    await loadState();
  }

  Future<void> changeStopTime(Timespan time, WorkDay dayToChange) async {
    await timeRepo.changeStopTime(time, dayToChange);
    await loadState();
  }
}
