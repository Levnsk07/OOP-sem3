//
// Created by leo on 29.10.2026.
//

#ifndef OOP_WORLDMAP_H
#define OOP_WORLDMAP_H


class WordMap {
    WordMap();

    ~WordMap();

    bool isWordExist(std::string word);

    void addWord(std::string word);

    void print();
};


#endif //OOP_WORLDMAP_H
