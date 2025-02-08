import 'package:handwerksapp/features/user/data/models/user_model.dart';
import 'package:isar/isar.dart';
part 'user_isar.g.dart';

@Collection()
class UserIsar {
  Id id = Isar.autoIncrement;
  final String email;
  final String password;
  final String name;

  UserIsar({
    required this.id,
    required this.email,
    required this.password,
    required this.name,
  });

  User toDomain() {
    return User(
      id: id,
      email: email,
      password: password,
      name: name,
    );
  }

  static UserIsar fromDomain(User newUser) {
    final statusIsar = UserIsar(
      id: newUser.id,
      email: newUser.email,
      password: newUser.password,
      name: newUser.name,
    );
    return statusIsar;
  }
}
