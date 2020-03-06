#include <algorithm>
#include "Word.h"

using namespace std;

#define INFINITE_WORD_DISTANCE -1

vector<pair<bool, string>> words;

string toupper(string data) {
    std::for_each(data.begin(), data.end(), [](char &c) {c = ::toupper(c);});
}

void readDictionary() {
    ifstream file;
    file.open("../german_dict.txt");
    if (!file.is_open()) return;

    pair<bool, string> word;
    word.first = false;
    while (file >> word.second)
        cout << word.second << endl;
}

int word_distance(string word_1, string word_2, Rule rule) {
    if(!rule.differentiate_capitalization) {
        word_1 = toupper(word_1);
        word_2 = toupper(word_1);
    }

    int total_distance = 0, current_distance = 0;

//    current_distance = swapDistance(word_1, word_2, rule);
//    if(rule.character_swap == false && current_distance > 0)
//        return INFINITE_WORD_DISTANCE;
//    total_distance += current_distance;
//
//    current_distance = characterAddDistance(word_1, word_2, rule);
//    if(rule.character_add == false && current_distance > 0)
//        return INFINITE_WORD_DISTANCE;
//    total_distance += current_distance;
//
//    current_distance = characterRemoveDistance(word_1, word_2, rule);
//    if(rule.character_remove == false && current_distance > 0)
//        return INFINITE_WORD_DISTANCE;
//    total_distance += current_distance;
//
//    current_distance = differentCapitaliztionDistance(word_1, word_2, rule);
//    if(rule.differentiate_capitalization == false && current_distance > 0)
//        return INFINITE_WORD_DISTANCE;
//    total_distance += current_distance;
//
//    current_distance = characterChangeDistance(word_1, word_2, rule);
//    if(rule.character_change == false && current_distance > 0)
//        return INFINITE_WORD_DISTANCE;
//    total_distance += current_distance;
//
//    current_distance = characterCountKeepDistance(word_1, word_2, rule);
//    if(rule.character_keep == false && current_distance > 0)
//        return INFINITE_WORD_DISTANCE;
//    total_distance += current_distance;

    return total_distance;
}
