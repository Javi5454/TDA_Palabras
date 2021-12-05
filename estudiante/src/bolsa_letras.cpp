//
// Created by Adrián Jaén on 05/12/2021.
//

#include "letters_bag.h"
#include "letters_set.h"
#include "iostream"
#include "fstream"

using namespace std;

int main(int argc, char* argv[]){

    string letters_file = argv[1];

    ifstream archivoletras;
    archivoletras.open(letters_file);

    if(archivoletras){
        LettersSet conjunto_letras;
        archivoletras >> conjunto_letras;

        LettersBag bolsa_letras(conjunto_letras);

        while(bolsa_letras.size() != 0){
            cout << bolsa_letras.extractLetter() << endl;
        }
    }
    else{
        cout << "No se pudo abrir el archivo :(";
    }

    return 0;
}