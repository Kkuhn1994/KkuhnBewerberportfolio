import 'package:flutter_bloc/flutter_bloc.dart';
import 'package:handwerksapp/features/user/data/models/user_model.dart';
import 'package:handwerksapp/features/user/data/repos/user_repo.dart';

class UserCubit extends Cubit<List<User>> {
  final UserRepo userRepo;

  int newState = 0;
  UserCubit(this.userRepo) : super([]);

  Future<void> loadState() async {
    final products = await userRepo.getUserList();
    emit(products);
  }

  Future<void> addUser(User newUser) async {
    await userRepo.addUser(newUser);
    loadState();
  }

  Future<User?> verifyUser(User user) async {
    return userRepo.searchUser(user);
  }
}
