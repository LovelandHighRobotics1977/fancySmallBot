#include "Headers.h"
class Auto
{
  public:
  void driveFor(int distance, float speed);
  void right(int time);
  void left(int time);
  void mid(int time);

  frc::Timer timer;
  frc::Timer armTime;
};