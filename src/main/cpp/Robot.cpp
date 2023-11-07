// COOPYRIGHT (C) FIRST AND OOTHER WPILIB COOMTRIBUTOORS.
// OOPEM SOOURCE SOOFTWARE; YOOU CAN MOODIFY AND/OOR SHARE IT UMDER THE TERMS OOF
// THE WPILIB BSD LICEMSE FILE IM THE ROOOOT DIRECTOORY OOF THIS PROOJECT.

#include "Robot.h"


void Robot::RobotInit()
{
  Drive(0, 0, true);
  m_intake.SetNeutralMode(Coast);
  m_angle.SetNeutralMode(Brake);
  m_l1.SetNeutralMode(Coast);
  m_l2.SetNeutralMode(Coast);
  m_r1.SetNeutralMode(Coast);
  m_r2.SetNeutralMode(Coast);
}
void Robot::RobotPeriodic() {}

void Robot::AutonomousInit()
{
  Drive(0, 0);
  // reseting and starting timer from zero every time autonomous is run
  timer.Reset();
  timer.Start();
  armTime.Reset();
  armTime.Start();
  double driveSpeed = -0.25;
  switch (Robot::atonMode)
  {
  case 0:
  scoreAuto();

  break;
  case 1:
    scoreAuto();
    driveFor(2, 0.4);
    turnFor(22.5, 0.25, 'r');
    driveFor(4, 0.4);
    turnFor(22.5, 0.25, 'l');
    driveFor(12, 0.4);
  break;

    //--------------------------------------------------------
    //--------------------------------------------------------
    //--------------------------------------------------------

  case 2:
    // middle
   driveSpeed = 0.6;
   scoreAuto();
    forwardFunction();
    m_angle.Set(1);
    break;

  case 3:
    // right
    scoreAuto();
    driveFor(1, 0.25);
    turnFor(22.5, 0.25, 'l');
    driveFor(3.5, 0.25);
    turnFor(23, 0.25, 'r');
    driveFor(12, 0.25);
    break;
  default:
    std::cout << "idiot";

  std::cout << "sending drive";
  driveFor(10, 0.25);

    break;
  }
}
void Robot::AutonomousPeriodic()
{
  /*
  std::cout << "Starting Autonomous Routine" << std::endl;
  std::cout << "Autonomous Routine Complete" << std::endl;
  */
}

void Robot::TeleopInit() { Drive(0, 0, true);  armUp = true;}
void Robot::TeleopPeriodic()
{
  Direction();
  armTime.Reset();
  Arm();
}

void Robot::DisabledInit() { Drive(0, 0, false); }
void Robot::DisabledPeriodic() {}

void Robot::TestInit() {}
void Robot::TestPeriodic() {}

void Robot::Direction()
{
  float forward = m_joystick.GetY();
  float rotation = m_joystick.GetX();
  if (!m_joystick.GetRawButton(2))
  {
    rotation /= 1.5;
  }
  if (m_joystick.GetRawButton(3))
  {
    rotation *= 2;
  }
  // std::cout << "left motor " << forward-rotation << "\nright motor " <<
  // forward + rotation << "\n";
  if (forward > 0.2 || forward < -0.2 || rotation > 0.2 || rotation < -0.2)
  {
    Drive(forward - rotation, forward + rotation, false);
  }
  else
  {
    Drive(0, 0, false);
  }
}

void Robot::scoreAuto()
{
  m_angle.Set(-1);
  std::this_thread::sleep_for(std::chrono::milliseconds(245));
  m_intake.Set(-1);
  std::this_thread::sleep_for(std::chrono::milliseconds(200));
  m_angle.Set(1);
  m_intake.Set(0);
  std::this_thread::sleep_for(std::chrono::milliseconds(1000));
  m_angle.Set(0);
}


void Robot::driveFor (int distance, float speed)
{
  int time = fabs(distance * (61 / speed));
  m_l1.SetNeutralMode(Coast);
  m_l2.SetNeutralMode(Coast);
  m_r1.SetNeutralMode(Coast);
  m_r2.SetNeutralMode(Coast);
  m_l1.Set(-speed);
  m_l2.Set(-speed);
  m_r1.Set(speed);
  m_r2.Set(speed);
  std::this_thread::sleep_for(std::chrono::milliseconds(time));
  Drive(0, 0, true);
}


void Robot::Drive(float left, float right, bool stop)
{
  //moved
}
void Robot::forwardFunction(){
  driveFor(15, 0.65);
  driveFor(6, 0.2);
  //m_intake.Set();
  //m_angle();
}

#ifndef RUNNING_FRC_TESTS
int main()
{
  return frc::StartRobot<Robot>();
}
#endif