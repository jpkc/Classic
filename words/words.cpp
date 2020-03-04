#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <utility>
#include <cctype>

using namespace std;

vector<pair<bool, string>> words;

struct {
    int number_of_changes;
    bool differentiate_capitalization;
    bool character_add;
    bool character_remove;
    bool character_change;
    bool character_swap;
} Rule;

void readDictionary() {
    ifstream file;
    file.open("../german_dict.txt");
    if (!file.is_open()) return;

    pair<bool, string> word;
    word.first = false;
    while (file >> word.second)
        cout << word.second << endl;
}

int word_distance(string word_1, string word_2) {
    if(!Rule.differentiate_capitalization) {
//        word_1 = toupper(word_1);
//        word_2 = toupper(word_1);
    }

}

int main() {
    string first_word = "lieben", last_word = "hassen";

    Rule.number_of_changes = 1;
    Rule.differentiate_capitalization = false;
    Rule.character_add = false;
    Rule.character_remove = false;
    Rule.character_change = true;

    readDictionary();
//    find_word_after(first_word, Rule);


//    std::cout << "Hello, World!" << std::endl;
//    //build word list
//    //set next word rule
//    //set depth
//    while(tem uma palavra que atende as regras)
//        coloca a palavra na lista
//        marca a palavra como usada
//
    return 0;
}
