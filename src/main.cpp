#include "main.h"

pros::Controller master(CONTROLLER_MASTER);
pros::Motor leftFront(-10,pros::v5::MotorGears::green, pros::v5::MotorUnits::degrees);
pros::Motor leftMiddle(-20,pros::v5::MotorGears::green, pros::v5::MotorUnits::degrees);
pros::Motor leftRear(-11,pros::v5::MotorGears::green, pros::v5::MotorUnits::degrees);
pros::Motor rightFront(15,pros::v5::MotorGears::green, pros::v5::MotorUnits::degrees);
pros::Motor rightMiddle(14,pros::v5::MotorGears::green, pros::v5::MotorUnits::degrees);
pros::Motor rightRear(16,pros::v5::MotorGears::green, pros::v5::MotorUnits::degrees);

pros::adi::DigitalOut clamp('a');

void initialize() {
}


void autonomous() {}

void opcontrol() {
	while (true) {

		int y = master.get_analog(ANALOG_LEFT_Y);
		int x = master.get_analog(ANALOG_RIGHT_X);
		//Removes stick drift 
		if (x < 15 && x > -15) {
			x = 0;
		}

		if (y < 15 && y > -15) {
			y = 0;
		}

		leftFront.move(y+x);
		leftMiddle.move(y+x);
		leftRear.move(y+x);
		rightFront.move(y-x);
		rightMiddle.move(y-x);
		rightRear.move(y-x);

		if (master.get_digital(pros::E_CONTROLLER_DIGITAL_L1)) {
			clamp.set_value(HIGH);
		} else {
			clamp.set_value(LOW);
		}

		pros::delay(20);

	}
}