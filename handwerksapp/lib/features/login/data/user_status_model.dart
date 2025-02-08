import 'package:equatable/equatable.dart';
import 'package:handwerksapp/features/user/data/models/user_model.dart';

class UserState extends Equatable {
  final User? state;
  const UserState(this.state);

  UserState copyWith({User? newState}) {
    return UserState(newState);
  }

  @override
  List<Object> get props => [];
}
