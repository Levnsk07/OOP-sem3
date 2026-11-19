//
// Created by leo on 15.09.2026.
//

#ifndef CPP_ADD_H
#define CPP_ADD_H

namespace Add {
    // AddTamplate.cpp
    template<typename T>
    T addTemplate(T a, T b) {
        return a + b;
    }
}

namespace Wrong {
    template<typename T>
    T addTemplate(T a, T b) {
        return a;
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
