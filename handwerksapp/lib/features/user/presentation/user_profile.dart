import 'package:flutter/material.dart';
import 'package:flutter_bloc/flutter_bloc.dart';
import 'package:handwerksapp/features/user/cubits/user_cubit.dart';
import 'package:handwerksapp/features/user/data/models/user_model.dart';

class UserProfile extends StatefulWidget {
  final User user;
  const UserProfile({super.key, required this.user});

  @override
  State<UserProfile> createState() => _UserProfileState();
}

class _UserProfileState extends State<UserProfile> {
  late final User user;
  TextEditingController prenameController = TextEditingController();

  void changeNameOfUser(User user, BuildContext context, String newName) async {
    await context.read<UserCubit>().addUser(user.copyWith(name: newName));
  }

  @override
  void initState() {
    user = widget.user;
    super.initState();
  }

  @override
  Widget build(BuildContext context) {
    return BlocBuilder<UserCubit, List<User>>(builder: (context, userList) {
      print(user.email);
      return Container(
          padding: const EdgeInsets.all(10),
          margin: const EdgeInsets.all(10),
          child: SingleChildScrollView(
            child: Column(
              children: [
                Text(user.name),
                TextFormField(
                  controller: prenameController,
                ),
                ElevatedButton(
                    onPressed: () =>
                        changeNameOfUser(user, context, prenameController.text),
                    child: const Text('safe'))
              ],
            ),
          ));
    });
  }
}
