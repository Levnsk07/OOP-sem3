#include <array>
#include <iostream>
#include <ostream>
#include <stdexcept>
#include <vector>

class Sensor {
private:
    const int factoryID;
    const int boxID;
    int currentTemp;
    std::array<int, 10> queueTemp;
    int counter;
    inline static int maxExID = 0;
    inline static int countOfObjects = 0;

public:
    inline static std::string class_name = "Sensor";

    Sensor(int currentTemp) : factoryID(maxExID++), boxID(maxExID) {
        // this->factoryID = factoryID;
        // this->boxID = boxID;

        if (-273 <= currentTemp && currentTemp <= 1000) {
            this->currentTemp = currentTemp;
            counter = 0;
            queueTemp[counter++] = currentTemp;

            countOfObjects++;
        } else {
            throw std::out_of_range("temp out of range (-273 : 1000)");
        }
    }

    Sensor(const Sensor &s) : factoryID(s.factoryID), boxID(s.boxID) {
        currentTemp = s.currentTemp;
        counter = s.counter;
        queueTemp = s.queueTemp;
        countOfObjects++;
    }

    ~Sensor() = default;

    void print() {
        std::cout << "factoryID: " << factoryID
                << " boxID: " << boxID
                << " currentTemp: " << currentTemp
                << " counter: " << counter
                << std::endl;
    }

    void setCurrentTemp(int currentTemp) {
        this->currentTemp = currentTemp;

        if (counter == 9) {
            counter = 0;
        }

        queueTemp[counter++] = currentTemp;
    }


    std::array<int, 10> getQueueTemp() {
        return queueTemp;
    }

    int getCounter() {
        return counter;
    }

public:
    int getBoxID() {
        return boxID;
    }

public:
    int getFactoryID() {
        return factoryID;
    }

public:
    int getCurrentTemp() {
        return currentTemp;
    }


    friend std::ostream &operator<<(std::ostream &os, const Sensor &obj) {
        return os
               << "factoryID: " << obj.factoryID
               << " boxID: " << obj.boxID
               << " currentTemp: " << obj.currentTemp
               << " counter: " << obj.counter;
    }

    friend std::istream &operator>>(std::istream &in, Sensor &s) {
        int temp = 0;
        in >> temp;
        s.setCurrentTemp(temp);
        return in;
    }

    static void print_count() {
        std::cout << countOfObjects << std::endl;
    }
};
