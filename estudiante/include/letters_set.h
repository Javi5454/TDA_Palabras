/**
 * @file letter_set.h
 * @brief Archivo de especificación del TDA letters_set
 * @author Adrián Jaén Fuentes
 * @author Javier Gómez López
 */

#ifndef __LETTER_SET_H__
#define __LETTER_SET_H__
#include <map>
#include <iostream>

using namespace std;

/**
 * @brief TDA LetterInfo
 *
 * Contiene información sobre un determinado carácter del juego de las
 * letras. En concreto, almacena información sobre el número de repeticiones de
 * la letra en la partida y de la puntuación que otorga al utilizarse en una
 * palabra
 */

struct LetterInfo{
    int repetitions;
    int score;
};

/**
 * @brief TDA LettersSet
 *
 * Este TDA representa un conjunto de letras, con la información necesaria para
 * jugar una partida al juego de las letras, es decir, el número de repeticiones
 * que tenemos de la letra y la puntuación que dicha letra otorga cuando se
 * utiliza en una palabra
 */

class LettersSet{
    /**
     * @page repLettersSet Representación del TDA LetterSet
     *
     * @section invLettersSet
     *
     * En nuestro LetterSet almacenamos la información de todas las letras que
     * existen en nuestro diccionario, con su frecuencia de aparición y su puntuación
     * asociada
     *
     * @section faLettersSet
     *
     * fa: tipo_rep ----> LettersSet
     *     map<char,LetterInfo> letters ----> letters_set
     *
     *     La estructura map<char,LetterInfo> representa el LettersSet
     */

private:
    map<char, LetterInfo> letters;

public:

    /**
     * @brief Constructor por defecto.
     *
     * Crear un LettersSet vacío
     */
    LettersSet();

    /**
     * @brief Constructor de copia
     * @param other LettersSet a copiar
     */
    LettersSet(const LettersSet &other);

    /**
     * @brief Inserta un elemento en el LetterSet
     * @param val Pareja de letra y LetterInfo asociada a insertar
     * @return boolenao que marca si se ha podido insertar la letra en el LettersSet.
     * La letra sólo se inserta correctamente si no estaba aún incluida en la colección.
     */
    bool insert(const pair<char, LetterInfo> &val);

    /**
     * @brief Elimina un carácter del LetterSet.
     * @param key Carácter a eliminar
     * @return Booloeano que indica si se ha podido eliminar correctamente la letra del
     * LettersSet
     */
    bool erase(const char &key);

    /**
     * @brief Limpia el contenido del LettersSet
     *
     * Elimina el contenido del LettersSet
     */
    void clear();

    /**
     * @brief Consulta si el LettersSet
     * @return true si el LetterSet está vacío, falso en caso contrario
     */
    bool empty();

    /**
     * @brief Tamaño del LetterSet.
     * @return Número de elementos en el LetterSet
     */
    unsigned int size() const;

    /**
     * @brief Calcula la puntuación dada una palabra.
     * @param word String con la palabra cuya puntuación queremos calcular
     * @return Puntuación de la palabra, calculada como la suma de los puntuaciones
     * de cada una de sus letras.
     */
    int getScore(string word);

    /**
     * @brief Sobrecarga del operador de asignación.
     * @param cl LetterSet a copiar
     * @return Referencia al objeto this para poder encadenar el operador
     */
    LettersSet& operator= (const LettersSet& cl);

    /**
     * @brief Sobrecarga del operador de consulta.
     *
     * Permite acceder a los elementos del map que hay en nuestra clase
     * @param val Carácter a consultar
     * @return Estrucura de tipo LetterInfo con la información del carácter consultado:
     * Número de repeticiones y puntuación
     */
    LetterInfo& operator[] (const char &val);

    /**
     * @brief Sobrecarga del operador de salida
     * @param os Flujo de salida, donde escribir el LettersSet
     * @param cl LettersSet que se escribe
     */
    friend ostream & operator<< (ostream& os, const LettersSet &cl){
        map<char, LetterInfo>::const_iterator p1;

        for(p1 = cl.letters.begin(); p1 != cl.letters.end(); p1++){
            pair<char, LetterInfo> element = *p1;

            os << element.first << " " << element.second.score << " " << element.second.repetitions;
            os << endl;
        }

        return os;
    }

    /**
     * @brief Sobrecarga del operador de entrada.
     * @param is Flujo de entrada, del que leer el LettersSet
     * @param cl LettersSet en el que almacenar la información leída.
     * @return
     */
    friend istream& operator>> (istream& is, LettersSet &cl){
        string to_add;

        getline(is, to_add);

        while(!is.eof()){
            getline(is, to_add);

            if(to_add != ""){
                char letter_to_enter = to_add[0];
                string s_quantity;
                int last_pos;

                for (int i = 2; to_add[i] != '\t' ; ++i) {
                    s_quantity += to_add[i];
                    last_pos = i;
                }

                int quantity = stoi(s_quantity);

                string s_score;

                for (int i = last_pos+2; i < to_add.length(); ++i) {
                    s_score += to_add[i];
                }

                int score = stoi(s_score);

                LetterInfo letterInfo;

                letterInfo.repetitions = quantity;
                letterInfo.score = score;

                pair<char, LetterInfo> to_enter;
                to_enter.first = letter_to_enter;
                to_enter.second = letterInfo;

                cl.insert(to_enter);
            }
        }

        return is;
    }
};
#endif
