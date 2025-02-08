import 'package:equatable/equatable.dart';

class User extends Equatable {
  final int id;
  final String email;
  final String password;
  final String name;

  const User({
    required this.id,
    required this.email,
    required this.password,
    required this.name,
  });

  User copyWith({int? id, String? email, String? password, String? name}) {
    return User(
      id: id ?? this.id,
      email: email ?? this.email,
      password: password ?? this.password,
      name: name ?? this.name,
    );
  }

  Map<String, dynamic> toJson() => {
        'id': id,
        'email': email,
        'password': password,
        'name': name,
      };

  factory User.fromJson(Map<String, dynamic> json) {
    return User(
      id: json['id'],
      email: json['email'],
      password: json['end'],
      name: json['name'],
    );
  }

  @override
  List<Object> get props => [id, email, password, name];
}
