//
// Created by leo on 15.09.2026.
//

#ifndef CPP_ADD_H
#define CPP_ADD_H


int add(int a, int b);
int randomAdd(int a, int b);

namespace Add {
    // AddTamplate.cpp
    template<typename T>
    T addTemplate(T a, T b) {
        return a + b;
    }
}


#include <random>
namespace randAdd {
    template<typename T>
    T addTemplate(T a) {
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<int> distrib(1, 100);
        return a + (T) distrib(gen);
    }
}

#endif
