import 'package:equatable/equatable.dart';
import 'package:handwerksapp/features/time/timespan_model.dart';

class WorkDay extends Equatable {
  final int id;
  final String date;
  final List<Timespan> workAndBreakTimes;

  const WorkDay(
      {required this.id, required this.date, required this.workAndBreakTimes});

  WorkDay copyWith({int, id, String? date, List<Timespan>? workAndBreakTimes}) {
    return WorkDay(
        id: id ?? this.id,
        date: date ?? this.date,
        workAndBreakTimes: workAndBreakTimes ?? this.workAndBreakTimes);
  }

  @override
  List<Object> get props => [date, workAndBreakTimes];
}
