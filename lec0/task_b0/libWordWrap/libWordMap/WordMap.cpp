// #include "WordMap.h"

#include <iostream>
#include <map>
#include <sstream>

class WordMap {
private:
    std::map<std::string, int> words;
    // std::unordered_map<std::string, int> words;
public:
    WordMap() {
        words = {};
    }

    ~WordMap() = default;

    bool isWordExist(std::string word) {
        return words.find(word) != words.end();
    }

    void addWord(std::string word) {
        if (isWordExist(word)) {
            words[word] = words[word] + 1;
        } else {
            words[word] = 1;
        }
    }

    void print() {
        for (std::pair<const std::string, int> &some: words) {
            std::cout << some.first << "\t" << some.second << "\t" << procentOfWord(some.first) << std::endl;
        }
    }

    int mapSize() {
        return words.size();
    }

    int countOfAllWords() {
        int counter = 0;
        for (std::pair<const std::string, int> &some: words) {
            counter += some.second;
        }

        return counter;
    }

    int countOfWord(std::string word) {
        if (isWordExist(word)) {
            return words[word];
        }
        return 0;
    }

    double procentOfWord(std::string word) { // TODO remake @link{countOfAllWords}, like one updateble int for more faster code
        return ((double) countOfWord(word)) / countOfAllWords();
    }


    std::string toString() {
        std::string result = "";
        for (std::pair<const std::string, int> &some: words) {
            result += "[" + some.first + " : ";
            result += some.second + "]";
        }
    }

    friend std::ostream &operator<<(std::ostream &os, const WordMap words) {
        std::string result = "";
        for (const std::pair<const std::string, int> &some: words.words) {
            result += "[" + some.first + " : ";
            result += (std::to_string(some.second)) + "], ";
        }
        return os << result;
    }

    std::map<std::string, int> getWordMap() {
        return words;
    }
};
