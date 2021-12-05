#include "letters_bag.h"
#include "letters_set.h"
#include "bag.h"

LettersBag::LettersBag() {
    letters.empty();
}

LettersBag::LettersBag(const LettersSet &lettersSet) {

    LettersSet aux_set = lettersSet;

    for(auto it = aux_set.begin(); it != aux_set.end(); ++it) {
        for (int j = 0; j < (*it).second.repetitions; ++j) {
            letters.add((*it).first);
        }
    }
}

void LettersBag::insertLetter(const char &i) {
    letters.add(i);
}

char LettersBag::extractLetter() {
    return letters.get();
}

vector<char> LettersBag::extractLetters(int num) {

    vector<char> v;
    for (int i = 0; i < num; ++i)
        v.push_back(letters.get());

    return v;
}

void LettersBag::clear() {
    letters.clear();
}

unsigned int LettersBag::size() const{
    return letters.size();
}

LettersBag &LettersBag::operator=(const LettersBag &other) {
    if(this != &other){
        this->letters = other.letters;
    }
    return *this;
}
