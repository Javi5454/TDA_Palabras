#include "letters_set.h"

LettersSet::LettersSet() {
    letters.clear();
}

LettersSet::LettersSet(const LettersSet &other) {
    letters = other.letters;
}

bool LettersSet::insert(const pair<char, LetterInfo> &val) {
    map<char, LetterInfo>::iterator p = letters.find(val.first);

    if(empty()){
        letters.insert(val);
        return true;
    }
    else{
        if (p == letters.end()){
            letters.insert(val);
            return true;
        }
        else{
            return false;
        }
    };
}

bool LettersSet::erase(const char &key) {
    if(letters.erase(key) == 0){
        return true;
    }
    else{
        return false;
    }
}

void LettersSet::clear(){
    letters.clear();
}

bool LettersSet::empty() {
    return (letters.empty());
}

unsigned int LettersSet::size() const {
    return letters.size();
}

int LettersSet::getScore(string word) {
    int result = 0;

    for (int i = 0; i < word.length(); ++i) {
        word[i] = toupper(word[i]);
    }

    for (int i = 0; i < word.length(); ++i) {
        map<char, LetterInfo>::iterator p1 = letters.find(word[i]);

        pair<char, LetterInfo> letter = *p1;

        result += letter.second.score;
    }

    return result;
}

LettersSet &LettersSet::operator=(const LettersSet &cl) {
    letters = cl.letters;

    return *this;
}


