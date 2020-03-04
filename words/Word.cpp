#include "Word.h"

using namespace std;

vector<pair<bool, string>> words;

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
//        word_1 = toupper(word_1);
//        word_2 = toupper(word_1);
    }

}
