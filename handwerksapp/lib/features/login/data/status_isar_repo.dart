import 'dart:convert';

import 'package:handwerksapp/features/login/data/status_isar.dart';
import 'package:handwerksapp/features/login/data/status_repo.dart';
import 'package:handwerksapp/features/login/data/user_status_model.dart';
import 'package:handwerksapp/features/user/data/models/user_model.dart';
import 'package:isar/isar.dart';

class IsarUserStatusRepo implements UserStatusRepo {
  final Isar db;

  IsarUserStatusRepo({required this.db});

  @override
  Future<void> login(String userName, String password, User? userID) async {
    late final statusIsar;
    if (userID == null) {
      statusIsar = StatusIsar(status: 'null');
    } else {
      statusIsar = StatusIsar(status: jsonEncode(userID.toJson()));
    }
    await db.writeTxn(() async {
      await db.statusIsars.put(statusIsar);
    });
  }

  @override
  Future<void> logout() {
    final StatusIsar statusIsar = StatusIsar.fromDomain(const UserState(null));
    return db.writeTxn(() => db.statusIsars.put(statusIsar));
  }

  @override
  Future<void> initState() async {
    final StatusIsar statusIsar = StatusIsar.fromDomain(const UserState(null));

    await db.writeTxn(() async {
      await db.statusIsars.put(statusIsar);
    });
    await db.statusIsars.get(statusIsar.id);
  }
}
