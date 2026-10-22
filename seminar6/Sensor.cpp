#include <stdexcept>
#include <vector>

class Sensor {
    const int factoryID;
    const int boxID;


    // int factoryID;
    // int boxID;
    int currentTemp;
    int queueTemp[10];
    int counter;

public:
    Sensor(int factoryID, int boxID, int currentTemp) : factoryID(factoryID), boxID(boxID) {
        // this->factoryID = factoryID;
        // this->boxID = boxID;

        if (-273 <= currentTemp && currentTemp <= 1000) {
            this->currentTemp = currentTemp;
            counter = 0;
            queueTemp[counter++] = currentTemp;
        } else {
        }
    }

public:
    void setCurrentTemp(int currentTemp) {
        this->currentTemp = currentTemp;

        if (counter == 9) {
            counter = 0;
        }

        queueTemp[counter++] = currentTemp;
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

public:
    int *getQueueTemp() {
        return queueTemp;
    }
};
