#include "letters_bag.h"

LettersBag::LettersBag() {
    letters;
}

LettersBag::LettersBag(const LettersBag &lettersSet) {
    letters = lettersSet.letters;
}
