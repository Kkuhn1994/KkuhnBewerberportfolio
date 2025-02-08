import 'package:flutter/material.dart';
import 'package:flutter_bloc/flutter_bloc.dart';
import 'package:handwerksapp/core/presentation/slider_card.dart';
import 'package:handwerksapp/features/time/service/time_service.dart';
import 'package:handwerksapp/features/time/time_cubit.dart';
import 'package:handwerksapp/features/time/timespan_model.dart';
import 'package:handwerksapp/features/time/work_day_model.dart';

class ChangeTimes extends StatelessWidget {
  final WorkDay dayToChange;

  const ChangeTimes({super.key, required this.dayToChange});

  @override
  Widget build(BuildContext context) {
    return BlocBuilder<TimeCubit, List<WorkDay>>(
      builder: (context, dayList) {
        final WorkDay updatedDay = dayList.firstWhere(
          (day) => day.id == dayToChange.id,
          orElse: () => dayToChange,
        );
        List<Timespan> timeList = updatedDay.workAndBreakTimes;
        return AlertDialog(
          title: Text("Arbeitszeiten ändern"),
          content: SizedBox(
              width: double.maxFinite,
              child: TimespanList(updatedDay: updatedDay, timeList: timeList)),
        );
      },
    );
  }
}

class TimespanList extends StatelessWidget {
  final WorkDay updatedDay;
  final List<Timespan> timeList;

  const TimespanList(
      {super.key, required this.updatedDay, required this.timeList});

  @override
  Widget build(BuildContext context) {
    DateTime now = DateTime.now();
    double startOfDay = DateTime(now.year, now.month, now.day)
        .millisecondsSinceEpoch
        .toDouble();
    return ListView.builder(
      itemCount: timeList.length,
      itemBuilder: (context, index) {
        final Timespan arbeitsTag = timeList[index];

        double startValue =
            arbeitsTag.start.millisecondsSinceEpoch.toDouble() - startOfDay;
        double endValue =
            arbeitsTag.end.millisecondsSinceEpoch.toDouble() - startOfDay;

        return SliderCard(
          titleWidget: Text(
              'Startzeit: ${arbeitsTag.start.hour}:${arbeitsTag.start.minute}'),
          sliderWidget: RangeSlider(
            values: RangeValues(startValue, endValue),
            min: 0,
            max: 86400000, // Ein Tag in Millisekunden
            divisions: 96, // 24 * 4 15 Minutenweise Schritte
            onChanged: (newValues) {
              changeTimeValues(newValues, context, index, updatedDay);
            },
          ),
        );
      },
    );
  }
}
