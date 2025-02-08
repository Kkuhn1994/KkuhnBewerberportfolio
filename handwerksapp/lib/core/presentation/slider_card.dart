import 'package:flutter/material.dart';

class SliderCard extends StatelessWidget {
  final Widget sliderWidget;
  final Widget titleWidget;
  const SliderCard(
      {super.key, required this.sliderWidget, required this.titleWidget});

  @override
  Widget build(BuildContext context) {
    return Card(
      margin: const EdgeInsets.symmetric(vertical: 8, horizontal: 10),
      child: ListTile(
        contentPadding: const EdgeInsets.all(10),
        title: titleWidget,
        subtitle: Column(
          crossAxisAlignment: CrossAxisAlignment.start,
          children: [sliderWidget],
        ),
      ),
    );
  }
}
