//
// Created by javi5454 on 2021-12-04.
//

#include <iostream>
#include <fstream>
#include <string>
#include "dictionary.h"
#include "letters_set.h"

using namespace std;

int main(int argc, char *argv[]) {
    string dictionary_file = argv[1];
    string letters_file = argv[2];

    Dictionary dictionary;
    LettersSet lettersSet;

    ifstream dictionary_input;

    dictionary_input.open(dictionary_file);

    if (dictionary_input) {
        while (dictionary_input) {
            string to_add;

            dictionary_input >> to_add;

            dictionary.insert(to_add);
        }
    }

    dictionary_input.close();

    ifstream letterSet_input;

    letterSet_input.open(letters_file);
    
    if(!letterSet_input){
        return 0;
    }

    letterSet_input >> lettersSet;

    LettersSet::iterator p1;

    cout << "Letra\tFAbs.\tFrel." << endl;
    int tam = dictionary.getTotalLetters();

    for (p1 = lettersSet.begin(); p1 != lettersSet.end(); p1++) {
        pair<char, LetterInfo> element = *p1;

        char c_element = element.first;
        c_element = tolower(c_element);

        int ocurrences = dictionary.getOcurrences(c_element);
        double relative = double(ocurrences)/tam;

        cout << char(toupper(c_element)) << "\t"<< ocurrences << "\t" << relative << endl;
    }

    return 0;
}
