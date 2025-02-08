import 'package:equatable/equatable.dart';

class Timespan extends Equatable {
  final int id;
  final DateTime start;
  final DateTime end;

  final String type;

  const Timespan({
    required this.id,
    required this.start, 
    required this.end,

    required this.type});

  Timespan copyWith({  
    int ?id,
    DateTime ?start,
    DateTime ?end,
    String ?date,
    String ?type,}) {
    return Timespan(
      id: id ?? this.id,
      start: start ?? this.start,
      end: end ?? this.end,
  
      type:type ?? this.type);
  }

  Map<String, dynamic> toJson() => {
        'id': id,
        'start': start.toIso8601String(),
        'end': end.toIso8601String(),

        'type': type
      };

  factory Timespan.fromJson(Map<String, dynamic> json) {
    return Timespan(
      id: json['id'],
      start: DateTime.parse(json['start']),
      end: DateTime.parse(json['end']),

      type: json['type'],
    );
  }
  @override
  List<Object> get props => [id, start, end, type];
}