import 'package:handwerksapp/features/login/data/status_isar.dart';
import 'package:handwerksapp/features/login/data/status_repo.dart';
import 'package:handwerksapp/features/login/data/user_status_model.dart';
import 'package:isar/isar.dart';

class IsarUserStatusRepo implements UserStatusRepo {
  final Isar db;

  IsarUserStatusRepo({required this.db});

  @override
  Future<void> login(String userName, String password) async {
    final statusIsar = StatusIsar(status: 1);
    try {
      await db.writeTxn(() async {
        await db.statusIsars.put(statusIsar);
      });
    } catch (e) {
      print('Fehler beim Speichern des Status: $e');
    }
  }

  @override
  Future<void> logout() {
    final StatusIsar statusIsar = StatusIsar.fromDomain(const UserState(0));
    return db.writeTxn(() => db.statusIsars.put(statusIsar));
  }

  @override
  Future<void> initState() async {
    final StatusIsar statusIsar = StatusIsar.fromDomain(const UserState(0));
    try {
      await db.writeTxn(() async {
        await db.statusIsars.put(statusIsar);
      });

      // Überprüfen, ob der Wert korrekt gespeichert wurde
      await db.statusIsars.get(statusIsar.id);
    } catch (e) {
      print('Fehler beim Speichern des Status: $e');
    }
  }
}
