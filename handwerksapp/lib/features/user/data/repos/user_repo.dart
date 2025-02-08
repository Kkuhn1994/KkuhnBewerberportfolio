import 'package:handwerksapp/features/user/data/models/user_model.dart';

abstract class UserRepo {
  Future<void> addUser(User newUser);

  Future<User?> searchUser(User user);

  Future<List<User>> getUserList();
}
