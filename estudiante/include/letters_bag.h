/**
 * @file letters_bag.h
 * @brief Archivo de especificación del TDA LettersBag
 * @author Adrián Jaén Fuentes
 * @author Javier Gómez López
 */

#ifndef __LETTERS_BAG_H__
#define __LETTERS_BAG_H__
#include <vector>
#include "bag.h"
#include "letters_set.h"

using namespace std;

/**
 * @brief TDA LettersBag
 *
 * Este TDA almacena un conjunto de chars utilizado en el juego de letras.
 * La estructura de datos subyacente es una lista de chars.
 */

class LettersBag{
    /**
     * @page repLettersBag Representación del TDA LettersBag
     *
     * @section invLettersBag
     *
     * En nuestro LetterBag se seleccionan letras con las que vamos a jugar una
     * partida de las letras.
     *
     * @section faLettersBag
     *
     * fa: tipo_rep ----> LettersBag
     *     Bag <char> ----> letters_bag
     *
     *     La estructura Bag<char> representa el LetterBag
     */

private:
    Bag <char> letters;

public:

    /**
     * @brief Constructor por defecto
     *
     * Inicializa el Bag<char> como vacío
     */
    LettersBag();

    /**
     * @brief Constructor dado un LettersSet
     *
     * Dado un LettersSet como argumento, este constructor debe rellenar la LettersBag
     * con las letras que contiene el LetterSet, introduciendo cada letra el número
     * de veces indicado por el campo LetterInfo::repetitions. Un ejemplo en el que se
     * utilice este constructor es el siguiente:
     * ~~~cpp
     * ifstream archivo_letras("letras.txt");
     *
     * LettersSet conjunto_letras;
     * archivo_letras >> conjunto_letras;
     *
     * LettersBag bolsa_letras(conjunto_letras);
     * ~~~
     *
     * @param lettersSet TDA LettersSet a parsear
     */
    explicit LettersBag(const LettersSet &lettersSet);

    /**
     * @brief Introduce una letra en la bolsa
     * @param l letra a añadir a la LettersBag
     */
    void insertLetter(const char &l);

    /**
     * @brief Extra una letra aleatoria de la bolsa.
     *
     * Extra una letra aleatoria de la bolsa, eliminándola del conjunto
     *
     * @return char representa la letra extraída
     */
    char extractLetter();

    /**
     * @brief Extra un conjunto de letras.
     *
     * Extra un conjunto de letras de la LettersBag, eliminándolas del conjunto
     * @param num Número de letras a extraer
     * @return Lista con las letras extraídas aleatoriamente
     */
    vector<char> extractLetters(int num);

    /**
     * @brief Vacía la LettersBag.
     *
     * Elimina todo el contenido de la LettersBag
     */
    void clear();

    /**
     * @brief Tamaño de la bolsa.
     * @return int con el tamaño de la bolsa.
     */
    unsigned int size() const;

    /**
     * @brief Sobrecarga del operador de asignación.
     * @return Referencia a this de esta forma el operador puede ser encadenado
     */
    LettersBag& operator= (const LettersBag& other);


};



#endif