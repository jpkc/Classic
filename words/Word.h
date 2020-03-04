#ifndef WORDS_WORD_H
#define WORDS_WORD_H

#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include <utility>
#include <cctype>

typedef struct {
    int number_of_changes;
    bool differentiate_capitalization;
    bool character_add;
    bool character_remove;
    bool character_change;
    bool character_swap;
} Rule;

void readDictionary();
int distance(std::string word_1, std::string word_2, Rule rule);
int distance(std::string word_1, std::string word_2);

#endif //WORDS_WORD_H
