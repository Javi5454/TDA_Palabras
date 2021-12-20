//
// Created by Adrián Jaén on 12/12/2021.
//

#include "../include/solver.h"

#include "iostream"
#include <utility>
#include "algorithm"
#include "string"

Solver::Solver(const Dictionary& dict, const LettersSet& letters_set) {
    this->dict = dict;
    this->letters_set = letters_set;
}

int Solver::wordScore(vector<char> available_letters, const string &word, bool score_game){

    vector<char> aux_letters(move(available_letters)); //O(n)
    int result = 0; //O(1)

    for(char current : word){ //O(n)
        vector<char>::iterator p1; //O(1)
        bool exist = false; //O(1)

        for(int i = 0; i < aux_letters.size(); i++){ //O(n)                         //
                                                                                    //
            if(toupper(current) == aux_letters[i]){ //O(1)                       //
                aux_letters[i] = aux_letters[aux_letters.size()-1]; // O(1)         // O(n^2)
                aux_letters.pop_back(); // O(1)                                     //
                exist = true; // O(1)                                               //
                break;                                                              //
            }
        }

        if(!exist) //O(1)
        {
            result = 0; //O(1)
            break; //O(1)
        }
        else
            result = (score_game ? letters_set.getScore(word) : word.length()); //O(1)
    }
    return result; //O(1)
}

pair<vector<string>, int> Solver::getSolutions(const vector<char> &available_letters, bool score_game) {

    int highest_score = 0; //O(1)
    vector<string> result; //O(1)

    const Dictionary aux; //O(1)
    Dictionary::iterator it; //O(1)

    for(it = dict.begin(); it != dict.end(); ++it){ //O(n)

        int curr_score = wordScore(available_letters, *it, score_game); //O(n(log(n))

        if (curr_score < highest_score) //O(1)
            continue;
        else if (curr_score > highest_score) { //O(1)
            highest_score = curr_score; //O(1)
            result.clear(); //O(n)
            result.push_back(*it); //O(1)
        } else {
            result.push_back(*it); //O(1)
        }
    }

    pair<vector<string>, int> solutions {result, highest_score};
    return solutions;
}




