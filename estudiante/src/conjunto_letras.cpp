//
// Created by javi5454 on 2021-12-05.
//
#include "letters_set.h"
#include <iostream>
#include <fstream>

int main(int argc, char *argv[]){
    string rute = argv[1];
    string word = argv[2];

    LettersSet lettersSet;

    ifstream input;

    input.open(rute);

    input >> lettersSet;

    int result = lettersSet.getScore(word);

    cout << result << endl;

    return 0;
}