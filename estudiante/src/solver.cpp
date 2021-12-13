//
// Created by Adrián Jaén on 12/12/2021.
//

#include "../include/solver.h"

#include <utility>
#include "algorithm"
#include "string"

Solver::Solver(const Dictionary& dict, const LettersSet& letters_set) {
    this->dict = dict;
    this->letters_set = letters_set;
}

bool Solver::possibleSol(vector<char> available_letters, const string &word){

    vector<char> aux_letters(move(available_letters));
    bool result = true;

    for(char current : word){
        vector<char>::iterator p1;
        bool exist = false;
        for(p1 = aux_letters.begin(); p1 != aux_letters.end(); p1++){
            if(toupper(current) == *p1){
                exist = true;
                break;
            }
        }

        if(!exist){
            result = false;
        }
    }

    return result;
}

Dictionary Solver::possibleWords(const vector<char> &available_letters) {
    Dictionary result;

    Dictionary::iterator p1;
    string current_word;

    for(p1 = dict.begin(); p1 != dict.end(); p1++){
        current_word = *p1;
        if(possibleSol(available_letters, current_word)){
            result.insert(current_word);
        }
    }

    return result;
}

pair<vector<string>, int> Solver::solveLongest(const Dictionary &dictionary) {
    int length_result = 0;
    pair<vector<string>, int> solution;
    vector<string> result;

    Dictionary::const_iterator p1;

    for(p1 = dictionary.begin(); p1 != dictionary.end(); p1++){
        string current_word = *p1;

        int length = current_word.length();

        if(length > length_result){
            length_result = length;
        }
    }

    result = dictionary.wordsOfLength(length_result);

    solution.first = result;
    solution.second = length_result;

    return solution;

}

pair<vector<string>, int> Solver::solveScore(const Dictionary &dict){
    return {};
}

pair<vector<string>, int> Solver::getSolutions(const vector<char> &available_letters, bool score_game) {
    Dictionary aux(possibleWords(available_letters));

    if(!score_game){
        return solveLongest(aux);
    } else
        return solveScore(aux);
}




