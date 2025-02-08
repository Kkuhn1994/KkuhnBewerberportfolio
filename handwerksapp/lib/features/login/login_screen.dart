import 'package:flutter/material.dart';
import 'package:flutter_bloc/flutter_bloc.dart';
import 'package:handwerksapp/features/user/cubits/user_cubit.dart';
import 'package:handwerksapp/features/login/Cubit/user_status_cubit.dart';
import 'package:handwerksapp/features/user/data/models/user_model.dart';

class LoginScreen extends StatefulWidget {
  final userStateCubit;
  final userCubit;
  const LoginScreen(
      {super.key, required this.userStateCubit, required this.userCubit});

  @override
  State<LoginScreen> createState() => _LoginSCreenState();
}

class _LoginSCreenState extends State<LoginScreen> {
  TextEditingController email = TextEditingController();
  TextEditingController password = TextEditingController();

  @override
  void initState() {
    super.initState();
  }

  void addUser(String email, String password) async {
    await context.read<UserCubit>().addUser(User(
        id: int.parse(DateTime.now().microsecondsSinceEpoch.toString()),
        email: email,
        password: password,
        name: ''));
  }

  void login(String email, String password) async {
    UserCubit userCubit = context.read<UserCubit>();
    await context.read<UserStatusCubit>().login(email, password, userCubit);
  }

  @override
  Widget build(BuildContext context) {
    return Center(
      child: Container(
        margin: const EdgeInsets.all(50),
        padding: const EdgeInsets.all(50),
        decoration: const BoxDecoration(
            color: Colors.white70,
            borderRadius: BorderRadius.all(Radius.circular(10))),
        child: Column(children: [
          const Text("Login"),
          TextFormField(
              controller: email,
              decoration: const InputDecoration(
                labelText: "Email",
              )),
          const SizedBox(height: 20),
          TextFormField(
              controller: password,
              decoration: const InputDecoration(
                labelText: "Password",
              )),
          const SizedBox(height: 50),
          ElevatedButton(
              onPressed: () => login(email.text, password.text),
              child: const Text('Login')),
          ElevatedButton(
              onPressed: () => addUser(email.text, password.text),
              child: const Text('Create Account'))
        ]),
      ),
    );
  }
}
