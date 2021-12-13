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

bool Solver::possibleSol(vector<char> available_letters, const string &word){

    vector<char> aux_letters(available_letters); //O(n)
    bool result = true; //O(1)

    for(size_t i = 0; i < word.length(); i++){ //O(n)
        vector<char>::iterator p1; //O(1)
        bool exist = false; //O(1)
        char current = word[i]; //O(1)

        for(p1 = aux_letters.begin(); p1 != aux_letters.end(); p1++){ //O(n)

            if(toupper(current) == *p1){ //O(1)
                aux_letters.erase(p1); //O(n)
                exist = true; //O(1)
                break;
            }
        }

        if(!exist){ //O(1)
            result = false; //O(1)
        }
    }

    return result; //O(1)
}

Dictionary Solver::possibleWords(const vector<char> &available_letters) {
    Dictionary result; //O(1)

    Dictionary::iterator p1; //O(1)
    string current_word; //O(1)

    for(p1 = dict.begin(); p1 != dict.end(); p1++){ //O(n)
        current_word = *p1; //O(1)
        if(possibleSol(available_letters, current_word)){ //O(n^3)
            result.insert(current_word); //O(log(n))
        }
    }

    return result; //O(1)
}

pair<vector<string>, int> Solver::solveLongest(const Dictionary &dict) {
    int length_result = 0; //O(1)
    pair<vector<string>, int> solution; //O(1)
    vector<string> result; //O(1)

    Dictionary::const_iterator p1; //O(1)

    for(p1 = dict.begin(); p1 != dict.end(); p1++){ //O(n)
        string current_word = *p1; //O(1)

        int length = current_word.length(); //O(1)

        if(length > length_result){ //O(1)
            length_result = length; //O(1)
        }
    }

    result = dict.wordsOfLength(length_result); //O(n)

    solution.first = result; //O(1)
    solution.second = length_result; //O(1)

    return solution;

}

pair<vector<string>, int> Solver::getSolutions(const vector<char> &available_letters, bool score_game) {
    Dictionary aux(possibleWords(available_letters));

    if(!score_game)
        return solveLongest(aux);
    else
        return solveScore(aux);
}

pair<vector<string>, int> Solver::solveScore(const Dictionary &dict) {

    int highest_score = 0; //O(1)
    vector<string> result; //O(1)

    Dictionary::const_iterator it; //O(1)

    for(it = dict.begin(); it != dict.end(); ++it){ //O(n)

        int curr_score = letters_set.getScore(*it); //O(n(log(n))

        if (curr_score < highest_score) //O(1)
            continue;
        else if (curr_score > highest_score) { //O(1)
            highest_score = curr_score; //O(1)
            result.clear(); //O(n)
            result.push_back(*it); //O(1)
        } else
            result.push_back(*it); //O(1)

    }

    pair<vector<string>, int> solution; //O(1)

    solution.first = result; //O(1)
    solution.second = highest_score; //O(1)

    return solution; //O(1)
}




