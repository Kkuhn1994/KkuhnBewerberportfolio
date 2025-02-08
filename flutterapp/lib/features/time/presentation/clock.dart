import 'dart:math';

import 'package:flutter/material.dart';
import 'package:flutter/scheduler.dart';

class ClockWidget extends StatefulWidget {
  const ClockWidget({super.key});

  @override
  _ClockWidgetState createState() => _ClockWidgetState();
}

class _ClockWidgetState extends State<ClockWidget>
    with TickerProviderStateMixin {
  late Ticker _ticker;
  DateTime _dateTime = DateTime.now();

  @override
  void initState() {
    super.initState();
    _ticker = createTicker((elapsed) {
      setState(() {
        _dateTime = DateTime.now();
      });
    })
      ..start();
  }

  @override
  void dispose() {
    _ticker.dispose();
    super.dispose();
  }

  @override
  Widget build(BuildContext context) {
    return AspectRatio(
      aspectRatio: 1,
      child: CustomPaint(
        painter: ClockPainter(_dateTime),
      ),
    );
  }
}

class ClockPainter extends CustomPainter {
  final DateTime dateTime;

  ClockPainter(this.dateTime);

  @override
  void paint(Canvas canvas, Size size) {
    final center = Offset(size.width / 2, size.height / 2);
    final radius = size.width / 2;

    final paint = Paint()
      ..color = Colors.black
      ..style = PaintingStyle.stroke
      ..strokeWidth = 8;

    final fillPaint = Paint()
      ..color = Colors.grey.shade900 // Farbe für den Hintergrund der Uhr
      ..style = PaintingStyle.fill;

    // Zeichne den Außenkreis
    canvas.drawCircle(center, radius, paint);
    canvas.drawCircle(center, radius, fillPaint);

    // Stundenzeiger
    final hourPaint = Paint()
      ..color = Colors.blue
      ..strokeWidth = 8
      ..strokeCap = StrokeCap.round;

    final minutePaint = Paint()
      ..color = Colors.green
      ..strokeWidth = 6
      ..strokeCap = StrokeCap.round;

    final secondPaint = Paint()
      ..color = Colors.red
      ..strokeWidth = 4
      ..strokeCap = StrokeCap.round;

    final hourAngle =
        (dateTime.hour % 12 + dateTime.minute / 60) * 30 * pi / 180;
    final minuteAngle = (dateTime.minute + dateTime.second / 60) * 6 * pi / 180;
    final secondAngle = dateTime.second * 6 * pi / 180;

    // Stundenzeiger
    canvas.drawLine(
      center,
      Offset(
        center.dx + 0.5 * radius * cos(hourAngle - pi / 2),
        center.dy + 0.5 * radius * sin(hourAngle - pi / 2),
      ),
      hourPaint,
    );

    // Minutenzeiger
    canvas.drawLine(
      center,
      Offset(
        center.dx + 0.7 * radius * cos(minuteAngle - pi / 2),
        center.dy + 0.7 * radius * sin(minuteAngle - pi / 2),
      ),
      minutePaint,
    );

    // Sekundenzeiger
    canvas.drawLine(
      center,
      Offset(
        center.dx + 0.9 * radius * cos(secondAngle - pi / 2),
        center.dy + 0.9 * radius * sin(secondAngle - pi / 2),
      ),
      secondPaint,
    );

    // Mittelpunkt
    final centerDotPaint = Paint()..color = Colors.white;
    canvas.drawCircle(center, 8, centerDotPaint);
  }

  @override
  bool shouldRepaint(covariant CustomPainter oldDelegate) => true;
}
