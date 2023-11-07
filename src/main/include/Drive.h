#include "Headers.h"
class Drive{
public:
void TeleDrive(float left, float right);
void TurnFor(float degrees, char direction, float speed);
void DriveFor(int feet, float speed);
//can ids
//motors
WPI_TalonFX m_l1{3};
WPI_TalonFX m_l2{4};
WPI_TalonFX m_r1{5};
WPI_TalonFX m_r2{6};
//input
frc::Joystick m_joystick{1};
};