#include "letters_bag.h"

LettersBag::LettersBag() {
    letters = Bag<char>();
}

LettersBag::LettersBag(const LettersSet &lettersSet) {

    for (int i = 0; i < lettersSet.size(); ++i) {

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
        return *this;
    }
}
