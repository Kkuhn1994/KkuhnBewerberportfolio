import 'dart:convert';

import 'package:handwerksapp/features/time/timespan_model.dart';
import 'package:handwerksapp/features/time/work_day_model.dart';
import 'package:isar/isar.dart';

part 'isar_workday.g.dart';

@Collection()
class IsarWorkday {
  Id id = Isar.autoIncrement;
  final String date;
  final List<String> workAndBreakTimes;

  IsarWorkday({
    required this.id,
    required this.date,
    required this.workAndBreakTimes,
  });

  WorkDay toDomain() {
    return WorkDay(
      id: id,
      date: date,
      workAndBreakTimes: workAndBreakTimes
          .map((t) => Timespan.fromJson(jsonDecode(t)))
          .toList(),
    );
  }

  static IsarWorkday fromDomain(WorkDay newTime) {
    final statusIsar = IsarWorkday(
      id: newTime.id,
      date: newTime.date,
      workAndBreakTimes:
          newTime.workAndBreakTimes.map((t) => jsonEncode(t.toJson())).toList(),
    );
    return statusIsar;
  }
}
