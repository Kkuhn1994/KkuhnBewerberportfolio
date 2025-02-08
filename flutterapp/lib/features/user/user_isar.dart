import 'package:handwerksapp/features/user/user_model.dart';
import 'package:isar/isar.dart';
part 'user_isar.g.dart';

@Collection()
class UserIsar {
  Id id = Isar.autoIncrement;
  final String email;
  final String password;

  UserIsar({required this.id, required this.email, required this.password});

  User toDomain() {
    return User(id: id, email: email, password: password);
  }

  static UserIsar fromDomain(User newUser) {
    final statusIsar = UserIsar(
        id: newUser.id, email: newUser.email, password: newUser.password);
    return statusIsar;
  }
}
