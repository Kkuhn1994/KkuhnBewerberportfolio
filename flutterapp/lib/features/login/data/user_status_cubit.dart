import 'package:flutter/material.dart';
import 'package:flutter/widgets.dart';
import 'package:flutter_bloc/flutter_bloc.dart';
import 'package:handwerksapp/features/user/user_cubit.dart';
import 'package:handwerksapp/features/user/user_model.dart';
import 'package:handwerksapp/features/login/data/status_isar.dart';
import 'package:handwerksapp/features/login/data/status_repo.dart';
import 'package:handwerksapp/features/login/data/user_status_model.dart';

abstract class StateDependableWidget extends StatelessWidget {
  const StateDependableWidget({super.key});
}

class UserStatusCubit extends Cubit<UserState> {
  final UserStatusRepo userStatusRepo;

  int newState = 0;
  UserStatusCubit(this.userStatusRepo) : super(const UserState(0));

  Future<void> initState() async {
    userStatusRepo.initState();
    await loadState(0);
  }

  Future<void> loadState(int newState) async {
    StatusIsar newStatus = StatusIsar(status: newState);
    newState = newStatus.toDomain();
    emit(UserState(newState));
  }

  Future<void> logout() async {
    await userStatusRepo.logout();
    await loadState(0);
  }

  Future<void> login(String name, String pw, UserCubit user) async {
    if (await user.verifyUser(User(id: 1, email: name, password: pw)) == true) {
      await userStatusRepo.login(name, pw);
      loadState(1);
    } else {
      print('password wrong');
    }
  }
}
