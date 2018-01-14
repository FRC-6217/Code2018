#ifndef JoystickDrive_H
#define JoystickDrive_H

#include "../CommandBase.h"

class JoystickDrive : public CommandBase {
public:
	JoystickDrive();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // JoystickDrive_H
