#include <iostream>
#include "Sensor.cpp"


int main(int argc, char *argv[]) {
    // Sensor* s = new Sensor(200);
    std::cout << "static values: " << std::endl;
    Sensor::print_count();
    std::cout << Sensor::class_name << std::endl;


    std::cout << "Book creation: " << std::endl;
    Sensor firstSensor(100);
    firstSensor.print();
    firstSensor.print_count();
    std::cout << firstSensor << std::endl;


    std::cout << "Second book: " << std::endl;
    Sensor secondSensor(150);
    std::cout << firstSensor << std::endl;
    secondSensor.setCurrentTemp(200);
    firstSensor.setCurrentTemp(250);
    secondSensor.print();

    {
        std::cout << " inside {} " << std::endl;
        Sensor secondSensor(firstSensor);
        std::cout << secondSensor << std::endl;
        secondSensor.setCurrentTemp(250);
        firstSensor.setCurrentTemp(250);
        secondSensor.print();
    }

    std::cout << " outside {} " << std::endl;
    secondSensor.print();
}
