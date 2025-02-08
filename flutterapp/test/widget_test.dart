// This is a basic Flutter widget test.
//
// To perform an interaction with a widget in your test, use the WidgetTester
// utility in the flutter_test package. For example, you can send tap and scroll
// gestures. You can also use WidgetTester to find child widgets in the widget
// tree, read text, and verify that the values of widget properties are correct.

import 'package:flutter/material.dart';
import 'package:flutter_test/flutter_test.dart';
import 'package:handwerksapp/features/time/data/repos/isar_time_repo.dart';
import 'package:handwerksapp/features/user/isar_user_repo.dart';
import 'package:handwerksapp/features/login/data/status_isar.dart';
import 'package:handwerksapp/features/login/data/status_isar_repo.dart';

import 'package:handwerksapp/main.dart';
import 'package:isar/isar.dart';
import 'package:path_provider/path_provider.dart';

void main() {
  testWidgets('Counter increments smoke test', (WidgetTester tester) async {
    final dir = await getApplicationDocumentsDirectory();

    final isar = await Isar.open(
      [StatusIsarSchema],
      directory: dir.path,
    );
    final isarStatusRepo = IsarUserStatusRepo(db: isar);
    final isarUserRepo = IsarUserRepo(db: isar);
    final isarTimeRepo = IsarTimeRepo(db: isar);
    // Build our app and trigger a frame.
    await tester.pumpWidget(MyApp(
      statusRepo: isarStatusRepo,
      userRepo: isarUserRepo,
      timeRepo: isarTimeRepo,
    ));

    // Verify that our counter starts at 0.
    expect(find.text('0'), findsOneWidget);
    expect(find.text('1'), findsNothing);

    // Tap the '+' icon and trigger a frame.
    await tester.tap(find.byIcon(Icons.add));
    await tester.pump();

    // Verify that our counter has incremented.
    expect(find.text('0'), findsNothing);
    expect(find.text('1'), findsOneWidget);
  });
}
