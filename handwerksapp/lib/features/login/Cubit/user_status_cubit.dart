import 'package:flutter/material.dart';
import 'package:flutter/widgets.dart';
import 'package:flutter_bloc/flutter_bloc.dart';
import 'package:handwerksapp/features/user/cubits/user_cubit.dart';
import 'package:handwerksapp/features/user/data/models/user_model.dart';
import 'package:handwerksapp/features/login/data/status_repo.dart';
import 'package:handwerksapp/features/login/data/user_status_model.dart';

abstract class StateDependableWidget extends StatelessWidget {
  const StateDependableWidget({super.key});
}

class UserStatusCubit extends Cubit<UserState> {
  final UserStatusRepo userStatusRepo;

  int newState = 0;
  UserStatusCubit(this.userStatusRepo) : super(const UserState(null));

  Future<void> initState() async {
    userStatusRepo.initState();
    await loadState(null);
  }

  Future<void> loadState(User? newState) async {
    //StatusIsar newStatus = StatusIsar(status: newState);
    //newState = newStatus.toDomain();
    emit(UserState(newState));
  }

  Future<void> logout() async {
    await userStatusRepo.logout();
    await loadState(null);
  }

  Future<void> login(String name, String pw, UserCubit userCubit) async {
    User? user = await userCubit
        .verifyUser(User(id: 1, email: name, password: pw, name: ''));
    if (user != null) {
      print('user found');
      await userStatusRepo.login(name, pw, user);
      loadState(user);
    }
  }
}
