//
// Created by Adrián Jaén on 12/12/2021.
//

#include "iostream"
#include "fstream"
#include "solver.h"
#include "letters_bag.h"

using namespace std;

int main(int argc, char *argv[]){

    if (argc != 5){
        cout << "Tiene que haber 4 argumentos:\n"
                "\t<Ruta al archivo que contiene las letras y su puntuación>\n"
                "\t<Ruta al archivo que contiene el diccionario>\n"
                "\t<Modo de juego (L = longitud, P = puntuación)>\n"
                "\t<Cantidad de letras para la partida>\n";
        exit(1);
    }

    string letters_file = argv[1];
    string dict_file = argv[2];
    string gamemode = argv[3];
    int letters_num = stoi(argv[4]);

    bool score_game;

    if(gamemode == "L")
        score_game = false;
    else if(gamemode == "P")
        score_game = true;
    else{
        cout << "Wrong gamemode";
        exit(1);
    }

    ifstream letters_input;
    letters_input.open(letters_file);

    // Letters_set

    LettersSet letters_set;
    letters_input >> letters_set;
    LettersBag bag(letters_set);
    vector<char> available_letters;

    available_letters.reserve(letters_num);
    for(int i = 0; i < letters_num; ++i){
        available_letters.push_back(bag.extractLetter());
    }

    // Dictionary

    ifstream dict_input;
    dict_input.open(dict_file);

    Dictionary dictionary;

    if (dict_input){
        while(!dict_input.eof()) {
            string to_add;
            dict_input >> to_add;

            if (to_add != ""){
                dictionary.insert(to_add);
            }
        }
    }
    dict_input.close();

    // Solution

    Solver solver(dictionary, letters_set);

    pair<vector<string>, int> solutions = solver.getSolutions(available_letters, score_game);

    cout << "LETRAS DISPONIBLES:" << endl;

    for (auto i:available_letters)
        cout << i << " ";

    cout << endl;

    cout << "SOLUCIONES:\n";

    for(auto & i : solutions.first){
        cout << i << endl;
    }

    cout << "PUNTUACION:\n" << solutions.second;


    return 0;
}









