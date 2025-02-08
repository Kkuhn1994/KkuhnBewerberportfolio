import 'package:handwerksapp/features/time/timespan_model.dart';
import 'package:handwerksapp/features/time/work_day_model.dart';

abstract class TimeRepo {
  Future<List<WorkDay>> getWorkDays();
  Future<void> startTime();
  Future<void> stopTime();

  Future<void> changeStartTime(Timespan time, WorkDay dayToChange);
  Future<void> changeStopTime(Timespan time, WorkDay dayToChange);
}
