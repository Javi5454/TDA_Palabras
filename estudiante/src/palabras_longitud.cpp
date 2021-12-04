//
// Created by javi5454 on 2021-12-04.
//

#include <iostream>
#include <fstream>
#include <string>
#include "dictionary.h"

using namespace std;

int main(int argc, char *argv[]){
    string dictionary_file = argv[1];
    int num_words = atoi(argv[2]);

    Dictionary my_dictionary;

    ifstream dictionary;

    dictionary.open(dictionary_file);

    if (dictionary){
        while(!dictionary.eof()) {
            string to_add;

            dictionary >> to_add;

            my_dictionary.insert(to_add);
        }
    }
    dictionary.close();

    vector<string> result;

    result = my_dictionary.wordsOfLength(num_words);

    cout << "Palabras de longitud " << num_words << endl;
    for (int i = 0; i < result.size(); ++i) {
        cout << result[i] << endl;
    }

    return 0;
}