import 'package:equatable/equatable.dart';

class UserState extends Equatable {
  final int state;
  const UserState(this.state);

  UserState copyWith({int? state}) {
    return UserState(state ?? 0);
  }

  @override
  List<Object> get props => [state];
}
