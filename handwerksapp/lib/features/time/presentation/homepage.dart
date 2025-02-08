import 'package:flutter/material.dart';
import 'package:flutter_bloc/flutter_bloc.dart';
import 'package:handwerksapp/features/time/presentation/change_times_modal.dart';
import 'package:handwerksapp/features/time/presentation/clock.dart';
import 'package:handwerksapp/features/time/time_cubit.dart';
import 'package:handwerksapp/features/time/work_day_model.dart';

class Homepage extends StatelessWidget {
  Homepage({super.key});

  void startWorktime(BuildContext context) async {
    await context.read<TimeCubit>().startTime();
  }

  void stopWorktime(BuildContext context) async {
    await context.read<TimeCubit>().stopTime();
  }

  void changeTime(BuildContext context, WorkDay dayToChange) {
    final timeCubit = context.read<TimeCubit>();
    showDialog(
        context: context,
        builder: (BuildContext context) {
          return BlocProvider.value(
              value: timeCubit,
              child: ChangeTimes(
                dayToChange: dayToChange,
              ));
        });
  }

  @override
  Widget build(BuildContext context) {
    return Row(
      children: [
        Column(
          children: [
            SizedBox(
              width: 300,
              height: 400,
              child: Column(children: [
                const ClockWidget(),
                const SizedBox(
                  height: 50,
                ),
                Row(
                  children: [
                    ElevatedButton(
                        onPressed: () => startWorktime(context),
                        child: const Text('Start Worktime')),
                    ElevatedButton(
                        onPressed: () => stopWorktime(context),
                        child: const Text('Stop Worktime')),
                  ],
                )
              ]),
            ),
          ],
        ),
        const SizedBox(
          width: 50,
        ),
        Expanded(
          child: BlocBuilder<TimeCubit, List<WorkDay>>(
              builder: (context, timeList) {
            if (timeList.isEmpty) {
              return const Text('no time worked');
            }
            return ListView.builder(
              itemCount: timeList.length, // Anzahl der Elemente in der Liste
              itemBuilder: (context, index) {
                final arbeitsTag =
                    timeList[index]; // Hole das aktuelle Element aus der Liste
                return Card(
                  margin:
                      const EdgeInsets.symmetric(vertical: 8, horizontal: 10),
                  child: ListTile(
                    contentPadding: const EdgeInsets.all(10),
                    title: Text('Datum: ${arbeitsTag.date}'),
                    subtitle: Column(
                      crossAxisAlignment: CrossAxisAlignment.start,
                      children: [
                        ElevatedButton(
                            onPressed: () =>
                                changeTime(context, timeList[index]),
                            child: const Text('edit'))
                      ],
                    ),
                  ),
                );
              },
            );
          }),
        )
      ],
    );
  }
}
