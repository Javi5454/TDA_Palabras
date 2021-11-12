/**
 * @file dictionary.h
 * @brief Archivo de especificación del TDA Dictionary
 * @author Adrián Jaén Fuentes
 * @author Javier Gómez López
 */

#ifndef __DICTIONARY_H__
#define __DICTIONARY_H__
#include <set>
#include <string>
#include <vector>

/**
 * @brief TDA Dictionary
 * @details Almacena las palabras de un fichero de texto y permite iterar sobre ellas
 *
 */

class Dictionary{
    /**
     * @page repDictionary Representación del TDA Dictionary
     *
     * @section invDictionary
     *
     * En nuestro Dictionary se mantendrán un cojunto de palabras. Como
     * no estaremos interesados en almacenar las definicones, solo los términos,
     * usaremos un tipo de dato "set"
     *
     * @section faDictionary Función de abstracción
     *
     * fa: tipo_rep ----> Dictionary
     *     set<string> ----> dictionary
     *
     *     La estructura set<string> representa el Dictionary
     */

private:
    /**
     * @brief Set formado por las palabras del diccionario
     */
    set<string> words;

public:

    /**
     * @brief Constructor por defecto.
     *
     * Crea un Dictionary vacío
     */
    Dictionary();

    /**
     * @brief Constructor de copia
     *
     * Crea un Dictionary con el mismo contenido que el que se pasa como argumento
     * @param other Dictionary que se quiere copiar
     */
    Dictionary(const Dictionary & other);

    /**
     * @brief Indica si una palabra está en el diccionario o no.
     *
     * Este método comprueba si una determinada palabra se enceuntra o no en el diccionario.
     * @param val La palabra que se quiere buscar.
     * @return Booleano indicando si la palabra existe o no en el diccioanrio
     */
    bool exists(const string &val) const;

    /**
     * @brief Inserta una palabra en el diccionario.
     * @param val Palabra a insertar en el diccionario
     * @return Booleano que indica si la insercción ha tenido éxito. Una palabra se inserta con éxito si no existía previamente en el diccionario.
     */
    bool insert(const string &val);

    /**
     * @brief Elimina una palabra del diccionario.
     * @param val Palabra a borrar del diccionario
     * @return Booleano que indica si la palabra se ha borrado del diccionario
     */
    bool erase(const string &val);

    /**
     * @brief Limpia el Dictionary
     *
     * Elimina todas las palabras contenidas en el conjunto
     */
    void clear();

    /**
     * @brief Comprueba si el diccionario está vacío.
     * @return True si el diccionario está vacío, false en caso contrario
     */
    bool empty();

    /**
     * @brief Tamaño del diccionario
     * @return Número de palabras guardadas en el diccionario
     */
    unsigned int size() const;

    /**
     * @brief Indica el número de apariciones de una letra
     * @param c letra a buscar
     * @return Un entero indicando el numero de aparaciones
     */
    int getOcurrences(const char c);

    /**
     * @brief Cuenta el total de letras de un diccionario.
     * @return Entero con el total de letras
     */
    int getTotalLetters();

    /**
     * @brief Devuelve las palabras en el diccionario con una longitud dada.
     * @param length Longitud de las palabras buscadas
     * @return Vector de palabras con la longitud deseada
     */
    vector<string> wordsOfLength(int length);
};

#endif
