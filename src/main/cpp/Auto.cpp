#include "Headers.h"
void Auto::left(int time){
  
}

void Auto::driveFor (int distance, float speed)
{
  int time = fabs(distance * (61 / speed));
  m_l1.SetNeutralMode(Brake);
  m_l2.SetNeutralMode(Brake);
   m_r1.SetNeutralMode(Brake);
    m_r2.SetNeutralMode(Coast);
  m_l1.Set(-speed);
  m_l2.Set(-speed);
  m_r1.Set(speed);
  m_r2.Set(speed);
  std::this_thread::sleep_for(std::chrono::milliseconds(time));
  Drive(0, 0, true);
}

void Robot::turnFor(float degrees, float speed, char direction)
{
  int time = fabs(degrees * (1.55 / speed));
  if (direction == 'r')
  {
    m_l1.Set(speed -
          (0.02 * (1 - speed)));
    m_l2.Set(speed -
          (0.02 * (1 - speed)));
    m_r1.Set(speed);
    m_r2.Set(speed);
  }
  else if (direction == 'l')
  {
    m_l1.Set(-speed);
    m_l2.Set(-speed);
    m_r1.Set(-speed);
    m_r2.Set(-speed);
  }
  std::this_thread::sleep_for(std::chrono::milliseconds(time));
  Drive(0, 0, true);
}