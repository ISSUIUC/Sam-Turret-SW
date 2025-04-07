#include <wiringPiI2C.h>
#include <iostream>
#include <unistd.h>

int main() {
    int i2c_address = 0x10; // real address
    int fd = wiringPiI2CSetup(i2c_address);

    if (fd == -1) {
        std::cerr << "Failed to initialize I2C communication.\n";
        return -1;
    }

    std::cout << "I2C communication successfully setup.\n";

    int command_register = 0x00;  // need real register
    int motor_speed = 0;

    int result = wiringPiI2CWriteReg8(fd, command_register, motor_speed);
    if (result == -1) {
        std::cerr << "Failed to write to the motor controller.\n";
    } else {
        std::cout << "Motor command sent successfully.\n";
    }
    return 0;
}
