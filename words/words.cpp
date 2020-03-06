#include <string>
#include "Word.h"

using namespace std;


int main() {
    string first_word = "lieben", last_word = "hassen";

    Rule rule;

    rule.number_of_changes = 1;
    rule.differentiate_capitalization = false;
    rule.character_add = false;
    rule.character_keep = true;
    rule.character_remove = false;
    rule.character_change = true;
    rule.character_swap = false;

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
