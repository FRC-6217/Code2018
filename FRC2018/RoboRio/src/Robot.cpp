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
		Drive->ArcadeDrive(joystick->GetX(), joystick->GetZ(), true);
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
