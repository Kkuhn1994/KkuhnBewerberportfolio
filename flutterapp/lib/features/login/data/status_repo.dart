abstract class UserStatusRepo {
  Future<void> login(String userName, String password);

  Future<void> logout();

  Future<void> initState();
}
