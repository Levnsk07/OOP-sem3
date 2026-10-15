
#include "../Add.h"
#include <random>
#include <iostream>



int add(int a, int b) {
    return a + b;
}

int add(int a) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> distrib(1, 100);
    return a + distrib(gen);
}
