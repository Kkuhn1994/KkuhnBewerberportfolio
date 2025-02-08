import 'dart:convert';

import 'package:handwerksapp/features/login/data/user_status_model.dart';
import 'package:handwerksapp/features/user/data/models/user_model.dart';
import 'package:isar/isar.dart';

part 'status_isar.g.dart';

@Collection()
class StatusIsar {
  Id id = Isar.autoIncrement;
  final String status;

  StatusIsar({required this.status});

  User? toDomain() {
    if (status != 'null') {
      return jsonDecode(status);
    }
    return null;
  }

  static StatusIsar fromDomain(UserState newstatus) {
    late final statusIsar;
    User? user = newstatus.state;
    if (user != null) {
      statusIsar = StatusIsar(status: jsonEncode(user.toJson()));
    } else {
      statusIsar = StatusIsar(status: 'null');
    }
    return statusIsar;
  }
}
