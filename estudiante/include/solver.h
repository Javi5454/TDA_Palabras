/**
 *   \file solver.h
 *   \brief Archivo de declaración de la clase Solver
 */
//
// Created by Adrián Jaén on 12/12/2021.
//

#ifndef P04_TDAS_NO_LINEALES_SOLVER_H
#define P04_TDAS_NO_LINEALES_SOLVER_H

#include "dictionary.h"
#include "letters_set.h"

class Solver {


private:
    Dictionary dict;
    LettersSet letters_set;


    /**
     * @brief Devuelve el valor de la palabra según el tipo de juego y de si se puede formar
     * con "available_letters", devuelve la puntuación si el juego es a puntos y la longitud si
     * es a longitud. Devuelve 0 si la palabra no se puede formar con "available_letters".
     * @param available_letters Vector de letras disponibles
     * @param word Palabra a comprobar
     * @param score_game Tipo de juego
     * @return Puntuación o longitud dependiendo de score_game, o 0 si no se puede consturir
     */
    int wordScore(vector<char> available_letters, const string &word, bool score_game);

public:

    /**
     * @brief Constructor con parámetros que crea un solver que tiene asociado un Dictionary u un LettersSet
     * @param dict
     * @param letters_set
     */
    Solver(const Dictionary& dict, const LettersSet& letters_set);

    /**
     * @brief Construye el vector de soluciones a partir de las letras de una partida.
     * Dado un conjunto de letras posibles para crear una solución, y el modo de juego con el que se juega la partida,
     * se construye un vector con las mejores soluciones encontradas en función del tipo de juego planteado.
     * @param available_letters Vector de letras disponibles para la partida
     * @param score_game Bool indicando el tipo de partida. True indica que la partida se juega a puntuación, false
     * que se juega a longitud
     * @return Par <vector<string>, int>, con el vector de palabras que constituyen las mejores funciones (puede haber
     * empates) y la puntuación que obtienen
     */
    pair<vector<string>, int>getSolutions(const vector<char> & available_letters, bool score_game);



};


#endif //P04_TDAS_NO_LINEALES_SOLVER_H
