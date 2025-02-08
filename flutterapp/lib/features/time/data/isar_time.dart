// import 'package:handwerksapp/time/timespan_model.dart';
// import 'package:isar/isar.dart';

// part 'isar_time.g.dart';

// @Collection()
// class TimeIsar {
//   Id id = Isar.autoIncrement;
//   final String start;
//   final String end;
//   final String type;


//   TimeIsar({
//     required this.id, 
//     required this.start, 
//     required this.end,
//     required this.type});

//   Timespan toDomain() {
//     return Timespan(
//       id: id, 
//       start: DateTime.parse(start), 
//       end: DateTime.parse(end), 
//       type: type);
//   }

//   static TimeIsar fromDomain(Timespan newTime) {
//     final statusIsar = 
//     TimeIsar(
//       id: newTime.id, 
//       start: newTime.start.toString(), 
//       end: newTime.end.toString(), 
//       type: newTime.type);
//     return statusIsar;
//   }
// }
