#include "Headers.h"
#include "Mech.h"
void Mech::Arm(bool up)
{
  //std::cout << m_joystick.GetRawAxis(4) << std::endl;
  //std::cout << "enterd arm up\n";
  if(m_xBox.GetXButtonPressed())
  {
    Robot::armspeed = 0.4;
  }
  else if (m_xBox.GetYButtonPressed())
  {
    Robot::armspeed = 0.6;
  }
  else if(m_xBox.GetBackButtonPressed())
  {
    Robot::armspeed = 1;
  }
  if(m_xBox.GetAButtonPressed())
  {
    scoreAuto();
  }
  if ( m_xBox.GetRawAxis(2) >= 0.2 && m_UpperSwitch.Get() == false)
  {
    m_angle.Set(-0.6);
  }
  else if (m_LowerSwitch.Get() == false && m_xBox.GetRawAxis(2) < 0.2 && m_xBox.GetRawAxis(3) < 0.2)
  {
    m_angle.Set(1);
  }
  else
  {
    m_angle.Set(0);
  }
  if (m_xBox.GetRawButton(6))
  {
    m_intake.Set(-Robot::armspeed);
    // std::cout << "intake in\n";
  }
  else if (m_xBox.GetRawButton(5))
  {
    m_intake.Set(0.4);
    // std::cout << "intake out";
  }
  else
  {
    m_intake.Set(0);
  }
}