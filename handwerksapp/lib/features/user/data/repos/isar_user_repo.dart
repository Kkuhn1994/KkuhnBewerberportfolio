import 'package:handwerksapp/features/user/data/models/user_model.dart';
import 'package:handwerksapp/features/user/data/models/user_isar.dart';
import 'package:handwerksapp/features/user/data/repos/user_repo.dart';
import 'package:isar/isar.dart';

class IsarUserRepo implements UserRepo {
  final Isar db;

  IsarUserRepo({required this.db});

  @override
  Future<List<User>> getUserList() async {
    final userIsar = await db.userIsars.where().findAll();
    return userIsar.map((user) => user.toDomain()).toList();
  }

  @override
  Future<void> addUser(User newUser) {
    final UserIsar userIsar = UserIsar.fromDomain(newUser);
    return db.writeTxn(() => db.userIsars.put(userIsar));
  }

  @override
  Future<User?> searchUser(User user) async {
    UserIsar user2 = UserIsar.fromDomain(user);
    final userIsars = await db.userIsars.where().findAll();
    for (UserIsar userIsar in userIsars) {
      if (userIsar.email == user2.email &&
          userIsar.password == user2.password) {
        return userIsar.toDomain();
      }
    }
    return null;
  }
}
