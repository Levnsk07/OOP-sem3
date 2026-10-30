// #include "WordWrap.h"

#include <iostream>
#include <string>
#include <vector>

#include "libWordMap/WordMap.cpp"

namespace WordWrap {
    std::string removeSymbol(const std::string line) {
        std::string result = "";
        for (char c: line) {
            if ((c == ' ') || (c == '\n') || (c == '\t') || ((c >= 65) && (c <= 90)) || ((c >= 97) && (c <= 122))) {
                result += c;
            }
        }
        return result;
    }

    std::vector<std::string> parsing(const std::string &line) {
        // FIXME dont remove spaces [DONE] but return spaces
        std::vector<std::string> result;
        std::string buffer = "";
        for (char c: line) {
            if ((c == ' ') || c == '\n' || c == '\t') {
                result.emplace_back(buffer);
                buffer = "";
            } else {
                buffer += c;
            }
        }
        return result;
    }


    WordMap createWordMap(const std::string line) {
        WordMap result;
        std::vector<std::string> words = parsing(line);
        for (std::string word: words) {
            result.addWord(word);
        }
        return result;
    }

    void addWord(const std::string startLine, WordMap &wordMap) {
        std::string line = removeSymbol(startLine);
        std::vector<std::string> words = parsing(line);
        for (std::string word: words) {
            wordMap.addWord(word);
        }
    }
}
