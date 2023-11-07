// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "Headers.h"
class Robot : public frc::TimedRobot {
 public:
  void RobotInit() override;
  void RobotPeriodic() override;

  void AutonomousInit() override;
  void AutonomousPeriodic() override;

  void TeleopInit() override;
  void TeleopPeriodic() override;
  //written to control left side and right side independantly with one line
  // Drive(Left side speed (-1 to 1), right side speed (-1 to 1))
  void Drive(float left, float right, bool stop);
  void Direction();
  void Arm();

  void DisabledInit() override;
  void DisabledPeriodic() override;

  void TestInit() override;
  void TestPeriodic() override;

  void scoreAuto();

  void forwardFunction();

  int atonMode = 1;
  //1 right
  //2 mid
  //3 left

  float armspeed = 0.4;
  bool armUp = true;

  private:
  //declaring power distabution for current limiting
  frc::PowerDistribution m_pdp{1, frc::PowerDistribution::ModuleType::kRev};
  //declaring mech motor
  WPI_TalonSRX m_angle{1};
  WPI_TalonSRX m_intake{2};
  //motor stuff
  WPI_TalonFX m_l1{5};
  WPI_TalonFX m_l2{6};
  WPI_TalonFX m_r1{3};
  WPI_TalonFX m_r2{4};
};