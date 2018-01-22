#ifndef _SINTACTICO
#define _SINTACTICO

#include "lexico.h"
#include "pila.h"
#include "arbolSintactico.h"

 class Sintactico{
       private:

           Pila pila;

           int fila, columna, accion;
           bool aceptacion;
           
           void muestraAccion(int accion);
           Nodo *arbolSintactico;
           
               
       public:
              Lexico lexico;
              Sintactico();  
              
              void analiza();
              
              void analizaGramatica0();
			  void analizaGramatica0_1();
              
       };


#endif