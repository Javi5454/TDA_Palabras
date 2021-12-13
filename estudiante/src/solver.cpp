//
// Created by Adrián Jaén on 12/12/2021.
//

#include "../include/solver.h"
#include "algorithm"
#include "string"

Solver::Solver(const Dictionary& dict, const LettersSet& letters_set) {
    this->dict = dict;
    this->letters_set = letters_set;
}

bool possibleSol(vector<char> available_letters, const string &word){

    for (char current : word){
        current = toupper(current);
        auto pos = find(available_letters.begin(), available_letters.end(), current);
        if (pos == available_letters.end())
            return false;
        else
            available_letters.erase(pos);
    }
    return true;
}

pair<vector<string>, int> Solver::getSolutions(const vector<char> &available_letters, bool score_game) {

    if (score_game){
        for(auto i = dict.begin(); i != dict.end(); ++i){
            (*i);
        }



    } else {
        for (unsigned int i = available_letters.size(); i > 0; --i) {
            cout << i << endl;
            vector<string> aux = dict.wordsOfLength(i);
            for(auto it = aux.begin(); it != aux.end(); ++it){
                if(!possibleSol(available_letters, *it)) {
                    aux.erase(it);
                }
            }
            if(aux.empty())
                continue;

            return {aux, aux.size()};
        }
    }
    return {};
}

