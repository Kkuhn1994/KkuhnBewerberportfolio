import 'package:handwerksapp/features/login/data/user_status_model.dart';
import 'package:isar/isar.dart';

part 'status_isar.g.dart';

@Collection()
class StatusIsar {
  Id id = Isar.autoIncrement;
  final int status;

  StatusIsar({required this.status});

  int toDomain() {
    return status;
  }

  static StatusIsar fromDomain(UserState newstatus) {
    final statusIsar = StatusIsar(status: newstatus.state);
    return statusIsar;
  }
}
