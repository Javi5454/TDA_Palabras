#include "dictionary.h"

Dictionary::Dictionary() {
    words.clear();
}

Dictionary::Dictionary(const Dictionary &other) {
    words = other.words;
}

bool Dictionary::exists(const std::string &val) const {
    if(words.find(val) != words.end()){
        return true;
    }
    else{
        return false;
    }
}

bool Dictionary::insert(const string &val) {
    if (exists(val)){
        return false;
    }
    else{
        words.insert(val);
        return true;
    }
}

bool Dictionary::erase(const string &val) {
    if (exists(val)){
        words.erase(val);
        return true;
    }
    else{
        return false;
    }
}

void Dictionary::clear() {
    words.clear();
}

bool Dictionary::empty() {
    if(size() == 0){
        return true;
    }
    else{
        return false;
    }
}

unsigned int Dictionary::size() const {
    return words.size();
}

int Dictionary::getOcurrences(const char c) {
    int result = 0;

    Dictionary::iterator p1;

    for (p1 = begin(); p1 != end(); p1++) {
        string word = *p1;
        int longitud = word.length();

        for (int i = 0; i < longitud; i++) {
            if(word[i] == c){
                result++;
            }
        }
    }

    return result;
}

int Dictionary::getTotalLetters() {
    int result = 0;

    set<string>::iterator p1;
    
    for(p1 = words.begin(); p1 != words.end(); p1++){
        string word = *p1;
        result += word.length();
    }

    return result;
}

vector<string> Dictionary::wordsOfLength(int length) const {
    vector<string> result;

    set<string>::iterator p1;

    for(p1 = words.begin(); p1 != words.end(); p1++){
        string word = *p1;

        if (word.length() == length){
            result.push_back(word);
        }
    }

    return result;
}
