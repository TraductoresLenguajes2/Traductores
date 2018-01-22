#ifndef _ARBOLSINTACTICO
#define _ARBOLSINTACTICO

#include <iostream>
#include "pila.h"
using namespace std;

//todos los elementos del árbol heredan de esta clase
  class Nodo{
        protected:
               string simbolo;
        public:
               static int tamSangria;                   
               Nodo *sig;
               Nodo (){ sig= NULL; }
               void sangria();
               virtual void muestra(){ cout << simbolo; }
        };


  
#endif