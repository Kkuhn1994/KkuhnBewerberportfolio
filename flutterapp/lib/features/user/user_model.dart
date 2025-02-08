import 'package:equatable/equatable.dart';

class User extends Equatable {
  final int id;
  final String email;
  final String password;

  const User({required this.id, required this.email, required this.password});

  User copyWith({User? oldUser}) {
    if (oldUser == null) {
      return User(id: id, email: email, password: password);
    }
    return User(
        id: oldUser.id, email: oldUser.email, password: oldUser.password);
  }

  @override
  List<Object> get props => [id];
}
