/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include <iostream>
#include <string>

#include <IterativeRobot.h>
#include <LiveWindow/LiveWindow.h>
#include <SmartDashboard/SendableChooser.h>
#include <SmartDashboard/SmartDashboard.h>
#include <WPILib.h>

#include "ctre/Phoenix.h"

class Robot : public frc::IterativeRobot {
public:

	//Objects for VictorSPX Motors and for the differentialDrive
	WPI_VictorSPX* flDrive;
	WPI_VictorSPX* blDrive;
	frc::SpeedControllerGroup* lDrive;
	WPI_VictorSPX* frDrive;
	WPI_VictorSPX* brDrive;
	frc::SpeedControllerGroup* rDrive;
	frc::DifferentialDrive* Drive;

	frc::Joystick* joystick;
	frc::Joystick* xboxJoystick;

	Spark* acmeScrew1;
	Spark* acmeScrew2;

	WPI_VictorSPX* grabberLeft;
	WPI_VictorSPX* grabberRight;

	void RobotInit() {
		m_chooser.AddDefault(kAutoNameDefault, kAutoNameDefault);
		m_chooser.AddObject(kAutoNameCustom, kAutoNameCustom);
		frc::SmartDashboard::PutData("Auto Modes", &m_chooser);

		flDrive = new WPI_VictorSPX(40);
		blDrive = new WPI_VictorSPX(41);
		lDrive = new frc::SpeedControllerGroup(*flDrive, *blDrive);

		frDrive = new WPI_VictorSPX(42);
		brDrive = new WPI_VictorSPX(43);
		rDrive = new frc::SpeedControllerGroup(*frDrive, *brDrive);

		Drive = new frc::DifferentialDrive(*lDrive, *rDrive);

		joystick = new frc::Joystick(0);
		xboxJoystick = new frc::Joystick(1);

		acmeScrew1 = new Spark(0);
		acmeScrew2 = new Spark(1);

		grabberLeft = new WPI_VictorSPX(45);
		grabberRight = new WPI_VictorSPX(46);
	}

	/*
	 * This autonomous (along with the chooser code above) shows how to
	 * select
	 * between different autonomous modes using the dashboard. The sendable
	 * chooser code works with the Java SmartDashboard. If you prefer the
	 * LabVIEW Dashboard, remove all of the chooser code and uncomment the
	 * GetString line to get the auto name from the text box below the Gyro.
	 *
	 * You can add additional auto modes by adding additional comparisons to
	 * the
	 * if-else structure below with additional strings. If using the
	 * SendableChooser make sure to add them to the chooser code above as
	 * well.
	 */
	void AutonomousInit() override {
		m_autoSelected = m_chooser.GetSelected();
		// m_autoSelected = SmartDashboard::GetString(
		// 		"Auto Selector", kAutoNameDefault);
		std::cout << "Auto selected: " << m_autoSelected << std::endl;

		if (m_autoSelected == kAutoNameCustom) {
			// Custom Auto goes here
		} else {
			// Default Auto goes here
		}
	}

	void AutonomousPeriodic() {
		if (m_autoSelected == kAutoNameCustom) {
			// Custom Auto goes here
		} else {
			// Default Auto goes here
		}
	}

	void TeleopInit() {}

	void TeleopPeriodic() {
		Drive->SetMaxOutput((joystick->GetRawAxis(3) - 1)/-1);

		float x = fabs(joystick->GetY()) > 0.15 ? joystick->GetY() : 0.0;
		float z = fabs(joystick->GetZ()) > 0.1 ? joystick->GetZ() : 0.0;

		Drive->ArcadeDrive(x, z, true);

		//controls Acme Screw 2
		if (xboxJoystick->GetRawAxis(2)){
			acmeScrew2->Set(-1); //up
		}
		else if (xboxJoystick->GetRawAxis(3)) {
			acmeScrew2->Set(1); //down
		}
		else {
			acmeScrew2->Set(0);
		}

		//Controls Acme Screw 1
		if (xboxJoystick->GetRawButton(5)){
			acmeScrew1->Set(-1); //up
		}
		else if (xboxJoystick->GetRawButton(6)){
			acmeScrew1->Set(1); //down
		}
		else {
			acmeScrew1->Set(0);
		}

		//controls Grabber Mechanism
		if (xboxJoystick->GetRawButton(1)){
			grabberLeft->Set(.5); //suck
			grabberRight->Set(.5);
		}
		else if (xboxJoystick->GetRawButton(2)) {
			grabberLeft->Set(-.5); //shoot
			grabberRight->Set(-.5);
		}
		else {
			grabberLeft->Set(0); //stop
			grabberRight->Set(0);
		}


	}

	void TestPeriodic() {}

private:
	frc::LiveWindow& m_lw = *LiveWindow::GetInstance();
	frc::SendableChooser<std::string> m_chooser;
	const std::string kAutoNameDefault = "Default";
	const std::string kAutoNameCustom = "My Auto";
	std::string m_autoSelected;
};

START_ROBOT_CLASS(Robot)
