#pragma once

//Included with timed robot skeleton
#include <frc/TimedRobot.h>
//Used to interface with xbox controller
#include <frc/XboxController.h>
//used to control talonSRX and falcon500(talonFX)
//must be added as a vendor library improtant
#include <ctre/Phoenix.h>
//output text library
#include <iostream>
//timer library
#include <frc/Timer.h>

#include <frc/DigitalInput.h>
#include <frc/Joystick.h>
#include <frc/PowerDistribution.h>
#include "Mech.h"
#include "Drive.h"
#include "Robot.h"
#include "Auto.h"
#include "Coords.h"
class Headers
{
    private:
    frc::PowerDistribution m_pdp{1, frc::PowerDistribution::ModuleType::kRev};
   //declaring mech motor
    WPI_TalonSRX m_angle{1};
    WPI_TalonSRX m_intake{2};
    //motor stuff
    WPI_TalonFX m_l1{3};
    WPI_TalonFX m_l2{4};
    WPI_TalonFX m_r1{5};
    WPI_TalonFX m_r2{6};
};