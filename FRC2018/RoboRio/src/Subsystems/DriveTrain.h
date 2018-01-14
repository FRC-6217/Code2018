#ifndef DriveTrain_H
#define DriveTrain_H

#include <Wpilib.h>

class DriveTrain : public Subsystem {
private:
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities

	VictorSP* flMotor;
	VictorSP* frMotor;
	VictorSP* blMotor;
	VictorSP* brMotor;

	frc::MecanumDrive* mecanumDrive;
public:
	DriveTrain();
	void InitDefaultCommand();

	void Move(frc::Joystick* joystick);
};

#endif  // DriveTrain_H
