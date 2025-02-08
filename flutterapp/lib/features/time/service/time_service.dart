import 'package:flutter/material.dart';
import 'package:flutter_bloc/flutter_bloc.dart';
import 'package:handwerksapp/features/time/time_cubit.dart';
import 'package:handwerksapp/features/time/work_day_model.dart';

void changeTimeValues(RangeValues newValues, BuildContext context, int index,
    WorkDay updatedDay) {
  DateTime now = DateTime.now();
  double startOfDay =
      DateTime(now.year, now.month, now.day).millisecondsSinceEpoch.toDouble();
  DateTime newStart = DateTime.fromMillisecondsSinceEpoch(
    (startOfDay + newValues.start).toInt(),
  );

  DateTime newEnd = DateTime.fromMillisecondsSinceEpoch(
    (startOfDay + newValues.end).toInt(),
  );
  context.read<TimeCubit>().changeStartTime(
      updatedDay.workAndBreakTimes[index].copyWith(start: newStart),
      updatedDay);
  context.read<TimeCubit>().changeStopTime(
      updatedDay.workAndBreakTimes[index].copyWith(end: newEnd), updatedDay);
}
