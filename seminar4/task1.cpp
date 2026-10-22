#include <algorithm>
#include <fstream>
#include <iostream>
#include <numeric>
#include <string>
#include <vector>

std::pmr::vector<int> parcing(std::ifstream in) {
    std::string line;
    std::pmr::vector<int> vectorTemp;

    const std::string templet[] = {", ", " "};

    while (std::getline(in, line)) {
        std::string number = "";

        // std::cout << line << std::endl;
        for (char c: line) {
            if (std::find(std::begin(*templet), std::end(*templet), c) != std::end(*templet) && number != "") {
                vectorTemp.push_back(atoi(number.c_str()));
                number = "";
            } else {
                number += c;
            }
        }
    }

    return vectorTemp;
}

int countOfNumber(const std::pmr::vector<int> vec, const int num) {
    int count = 0;
    for (int i: vec) {
        if (i == num) { count++; }
    }
    return count;
}


int main(int argc, char *argv[]) {
    std::pmr::vector<int> vec1;
    std::pmr::vector<int> vec2;

    std::ifstream in;

    in.open("s04_v1_42_1.txt");
    vec1 = parcing(std::move(in));

    in.open("s04_v1_42_2.txt");
    vec2 = parcing(std::move(in));
    std::cout << "count: " << vec1.size() << " | " << vec2.size() << std::endl;



    std::cout << "\t get last element -> " << *(std::end(vec1).operator--()) << std::endl; // show last element

    std::cout << "Numbers for vec1:\n";
    for (int vec11: vec1) {
        // int counter = countOfNumber(vec1, vec11);
        int counter = std::count(vec1.begin(), vec1.end(), vec11);
        std::cout << vec11 << ":" << counter << " | ";
    }

    std::cout << "\nNumbers for vec2:\n";
    for (int vec21: vec2) {
        // int counter = countOfNumber(vec2, vec21);
        int counter = std::count(vec2.begin(), vec2.end(), vec21);
        std::cout << vec21 << ":" << counter << " | ";
    }

    std::cout << "\nsum: " << std::accumulate(vec1.begin(), vec1.end(), 0) << " | " << std::accumulate(
        vec2.begin(), vec2.end(), 0) << std::endl;

    // int sum = 0;
    // std::for_each(vec1.begin(), vec2.end(), [&sum](int n) {
    //     sum += n;
    // });


    // ======       HW      ============
    std::cout << "Бинарная операция " << std::accumulate(vec1.begin(), vec1.end(), 0,
                                                         [](int a, int b)-> int { return b % 2 == 0 ? a + b : a - b; }
    ) << std::endl;

    std::cout << "\nNumbers for vec2 > 2 in vec1 > 3:\n";
    for (int vec21: vec2) {
        // int counter = countOfNumber(vec2, vec21)> 2 ? vec21 : -1;
        int more2 = std::count(vec2.begin(), vec2.end(), vec21) > 2 ? vec21 : -1;
        if (more2 == -1) continue;

        int more3 = std::count(vec1.begin(), vec1.end(), vec21) > 3 ? more2 : -1;
        if (more3 == -1) continue;
        std::cout << more3 << ":" << std::count(vec1.begin(), vec1.end(), vec21) << " | ";
    }


    in.close();
}
