#include "DriveTrain.h"
#include <Wpilib.h>
#include "../RobotMap.h"

DriveTrain::DriveTrain() : Subsystem("ExampleSubsystem") {

	flMotor = new frc::VictorSP(FL_MOTOR);
	frMotor = new frc::VictorSP(FR_MOTOR);
	blMotor = new frc::VictorSP(BL_MOTOR);
	brMotor = new frc::VictorSP(BR_MOTOR);

	frMotor->SetInverted(true);
	brMotor->SetInverted(true);

	mecanumDrive = new frc::MecanumDrive(flMotor, frMotor, blMotor, brMotor);
}

void DriveTrain::InitDefaultCommand() {
	// Set the default command for a subsystem here.
	// SetDefaultCommand(new MySpecialCommand());
}

// Put methods for controlling this subsystem
// here. Call these from Commands.

void DriveTrain::Move(frc::Joystick* joystick) {

	mecanumDrive->DriveCartesian(joystick->GetX(),joystick->GetY(), joystick->GetTwist());
}
