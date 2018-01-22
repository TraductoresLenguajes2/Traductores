#include <cstdlib>
#include <iostream>
#include "pila.h"

#include "lexico.h"
#include "sintactico.h"

using namespace std;

int main(int argc, char *argv[]){

    Sintactico sintactico;
    sintactico.lexico.entrada("a");
    sintactico.analiza();
    
  
    system("PAUSE");
    return EXIT_SUCCESS;
}
