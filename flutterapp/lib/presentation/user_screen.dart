import 'package:flutter/material.dart';
import 'package:flutter_bloc/flutter_bloc.dart';
import 'package:handwerksapp/features/login/Cubit/user_status_cubit.dart';
import 'package:handwerksapp/features/time/presentation/homepage.dart';

class WorkerScreen extends StatefulWidget {
  final userStateCubit;
  const WorkerScreen({super.key, required this.userStateCubit});

  @override
  State<WorkerScreen> createState() => _WorkerScreenState();
}

class _WorkerScreenState extends State<WorkerScreen> {
  int bodyContent = 0;
  @override
  void initState() {
    super.initState();
  }

  void choseBodyContent(int i) {
    setState(() {
      bodyContent = i;
    });
  }

  @override
  Widget build(BuildContext context) {
    Widget displayWidget;
    switch (bodyContent) {
      case 0:
        displayWidget = Homepage();
        break;
      case 1:
        displayWidget = const Text('Dies ist der zweite Zustand');
        break;
      case 2:
        displayWidget = const Text('Dies ist der dritte Zustand');
        break;
      case 3:
        displayWidget = const Text('Dies ist der vierte Zustand');
        break;
      default:
        displayWidget = const Text('Unbekannter Zustand');
    }
    return Scaffold(
        appBar: AppBar(
          title: Row(
            children: [
              ElevatedButton(
                  onPressed: () => choseBodyContent(0),
                  child: const Text('Homepage')),
              ElevatedButton(
                  onPressed: () => choseBodyContent(1),
                  child: const Text('Profil bearbeiten')),
              ElevatedButton(
                  onPressed: () => choseBodyContent(2),
                  child: const Text('Aufträge suchen')),
              ElevatedButton(
                  onPressed: () => choseBodyContent(3),
                  child: const Text('Rechnungen und Papiere')),
            ],
          ),
          actions: [
            ElevatedButton(
                onPressed: () => context.read<UserStatusCubit>().logout(),
                child: const Text('Logout')),
          ],
          toolbarHeight: 60.0,
          backgroundColor: Colors.black12,
        ),
        body: Expanded(
            child: Container(
                margin: const EdgeInsets.only(left: 50, bottom: 50, right: 50),
                padding: const EdgeInsets.all(50),
                decoration: const BoxDecoration(
                    color: Colors.white70,
                    borderRadius: BorderRadius.all(Radius.circular(10))),
                child: displayWidget)));
  }
}

// class LoggedInScreen extends StateDependableWidget {
//   final userStateCubit;
//   const LoggedInScreen({super.key, required this.userStateCubit});

//   @override
//   Widget build(BuildContext context) {
//     return 
//   }
// }

