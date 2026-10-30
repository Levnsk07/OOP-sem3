#include <fstream>
#include <string>

// #include "libWordWrap/libWordMap/WordMap.cpp"
#include "libWordWrap/WordWrap.cpp"
// #include "libWordMap/WordMap.h"

int main(int argc, char *argv[]) { // TODO work only with eng texts
    const std::string input = argv[1];
    const std::string output = argv[2];

    std::ifstream inFile(input);
    std::ofstream outFile(output);

    std::string line;
    WordMap wordMap;

    while (std::getline(inFile, line)) {
        WordWrap::addWord(line, wordMap);
    }

    inFile.close();

    // std::cout << wordMap << std::endl;

    outFile << "word ; count ; procent" << std::endl;
    for (const std::pair<std::string, int> p: wordMap.getWordMap()) {
        outFile << p.first << " ; " << p.second << " ; " << wordMap.procentOfWord(p.first) << std::endl;
    }

    outFile.close();
}
