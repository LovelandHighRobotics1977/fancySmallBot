#include "Headers.h"
class Mech{
  void Arm(bool up);
  void Intake(bool in);
  void SetSpeed(int speed);
  void AutoScore();

  //can ids
  //motors
  WPI_TalonSRX m_angle{1};
  WPI_TalonSRX m_intake{2};
  //input
  frc::XboxController m_xBox{0};
  //limit switches
  frc::DigitalInput m_LowerSwitch{0};
  frc::DigitalInput m_UpperSwitch{1};
};