import 'package:handwerksapp/features/user/data/models/user_model.dart';

abstract class UserStatusRepo {
  Future<void> login(String userName, String password, User? user);

  Future<void> logout();

  Future<void> initState();
}
