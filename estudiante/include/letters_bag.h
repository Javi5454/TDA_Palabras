#ifndef __LETTERS_BAG_H__
#define __LETTERS_BAG_H__

#include "bag.h"
#include "fstream"


/**
 * @brief TDA LettersBag
 *
 * Este TDA almacena un conjunto de chars utilizado en el juego de letras.
 * La estructura de datos subyacente es una lista de chars.
 */

class LettersBag {
private:
    Bag<char> letters;
public:

    /**
     *
     */
    LettersBag();

    /**
     *
     * @param i
     */
    void insertLetter(const char &i);

    /**
     *
     * @return
     */
    char extractLetter();

    /**
     *
     * @param num
     * @return
     */
    vector<char> extractLetters(int num);

    /**
     *
     */
    void clear();

    /**
     *
     * @return
     */
    int size();

    /**
     *
     * @param other
     * @return
     */
    LettersBag& operator=(const LettersBag& other);

};

#endif

