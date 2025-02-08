import 'package:flutter_bloc/flutter_bloc.dart';
import 'package:handwerksapp/features/user/user_model.dart';
import 'package:handwerksapp/features/user/user_repo.dart';

class UserCubit extends Cubit<List<User>> {
  final UserRepo userRepo;

  int newState = 0;
  UserCubit(this.userRepo) : super([]);

  Future<void> loadState() async {
    final products = await userRepo.getUserList();
    emit(products);
  }

  Future<void> addUser(User newUser) async {
    userRepo.addUser(newUser);
    loadState();
  }

  Future<bool> verifyUser(User user) async {
    return userRepo.searchUser(user);
  }
}
