import 'package:handwerksapp/features/user/user_model.dart';

abstract class UserRepo {
  Future<void> addUser(User newUser);

  Future<bool> searchUser(User user);

  Future<List<User>> getUserList();
}
