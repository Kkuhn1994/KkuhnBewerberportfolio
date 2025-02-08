import 'package:flutter/material.dart';
import 'package:flutter_bloc/flutter_bloc.dart';
import 'package:handwerksapp/features/time/data/isar_time.dart';
import 'package:handwerksapp/features/time/data/isar_workday.dart';
import 'package:handwerksapp/features/time/data/repos/isar_time_repo.dart';
import 'package:handwerksapp/features/time/time_cubit.dart';
import 'package:handwerksapp/features/time/data/time_repo.dart';
import 'package:handwerksapp/features/user/user_cubit.dart';
import 'package:handwerksapp/features/login/Cubit/user_status_cubit.dart';
import 'package:handwerksapp/features/user/isar_user_repo.dart';
import 'package:handwerksapp/features/login/data/status_isar.dart';
import 'package:handwerksapp/features/login/data/status_isar_repo.dart';
import 'package:handwerksapp/features/login/data/status_repo.dart';
import 'package:handwerksapp/features/login/data/user_status_model.dart';
import 'package:handwerksapp/features/user/user_isar.dart';
import 'package:handwerksapp/features/user/user_repo.dart';
import 'package:handwerksapp/features/login/login_screen.dart';
import 'package:handwerksapp/presentation/user_screen.dart';
import 'package:isar/isar.dart';
import 'package:path_provider/path_provider.dart';

Future<void> clearDatabase(Isar isar) async {
  // Alle Sammlungen leeren
  await isar.writeTxn(() async {
    // Dies entfernt alle Einträge in allen Sammlungen
    await isar.clear();
  });
}

void main() async {
  WidgetsFlutterBinding.ensureInitialized();
  final dir = await getApplicationDocumentsDirectory();

  final isar = await Isar.open(
    [StatusIsarSchema, UserIsarSchema, IsarWorkdaySchema],
    directory: dir.path,
  );
  await clearDatabase(isar);
  final isarStatusRepo = IsarUserStatusRepo(db: isar);
  final isarUserRepo = IsarUserRepo(db: isar);
  final isarTimeRepo = IsarTimeRepo(db: isar);
  isarStatusRepo.initState();
  runApp(
    MyApp(
      statusRepo: isarStatusRepo,
      userRepo: isarUserRepo,
      timeRepo: isarTimeRepo,
    ),
  );
}

class MyApp extends StatelessWidget {
  final UserStatusRepo statusRepo;
  final UserRepo userRepo;
  final TimeRepo timeRepo;
  const MyApp(
      {super.key,
      required this.statusRepo,
      required this.userRepo,
      required this.timeRepo});

  @override
  Widget build(BuildContext context) {
    return MaterialApp(
      title: 'Flutter Demo',
      theme: ThemeData(
        colorScheme: ColorScheme.fromSeed(seedColor: Colors.deepPurple),
        useMaterial3: true,
      ),
      home: CubitProvider(
        userStatus: statusRepo,
        userRepo: userRepo,
        timeRepo: timeRepo,
      ),
    );
  }
}

class CubitProvider extends StatelessWidget {
  final UserStatusRepo userStatus;
  final UserRepo userRepo;
  final TimeRepo timeRepo;
  const CubitProvider(
      {super.key,
      required this.userStatus,
      required this.userRepo,
      required this.timeRepo});

  @override
  Widget build(BuildContext context) {
    return MultiBlocProvider(
      providers: [
        BlocProvider(create: (_) => UserStatusCubit(userStatus)),
        BlocProvider(create: (_) => UserCubit(userRepo)),
        BlocProvider(create: (_) => TimeCubit(timeRepo)),
      ],
      child: MyHomePage(userStatus: userStatus),
    );
  }
}

class MyHomePage extends StatelessWidget {
  final UserStatusRepo userStatus;
  const MyHomePage({super.key, required this.userStatus});

  @override
  Widget build(BuildContext context) {
    return Scaffold(
        appBar: AppBar(title: const Center(child: Text('Freelancer Platform'))),
        body:
            BlocBuilder<UserStatusCubit, UserState>(builder: (context, state) {
          final userStatusCubit = context.read<UserStatusCubit>();
          final userCubit = context.read<UserCubit>();
          if (state == const UserState(0)) {
            return LoginScreen(
                userStateCubit: userStatusCubit, userCubit: userCubit);
          } else {
            return WorkerScreen(userStateCubit: userStatusCubit);
          }
        }));
  }
}
