#include "sintactico.h"
using namespace std;

 int Nodo::tamSangria= 0;

 Sintactico::Sintactico(){
 }

void  Sintactico::analiza(){
      aceptacion= false;
      lexico.sigSimbolo();
      
      analizaGramatica0();
      
      if (aceptacion){
        pila.pop();
        arbolSintactico= pila.pop()->nodo;
        cout << endl << "Arbol= " ;
        if (arbolSintactico != NULL) {
          cout << endl;
          arbolSintactico->muestra();
          cout << endl << endl;

        }
        else cout << "Vacio" << endl;
      }
                      
      
 }

void Sintactico::muestraAccion(int accion){
     cout << "Accion: " ;
     if (accion == 0)     
      cout << "Error" << endl;
      else
     if (accion > 0)
      cout << "d" << accion << endl;
      else
      if (accion == -1){
         cout << "Aceptacion" << endl;
         aceptacion= true;
      }   
      else
      if (accion < -1)
         cout << "r" << -(accion+1) << endl;

     } 
 
void Sintactico::analizaGramatica0(){      
    //gramatica0 <Expresion> ::= <id>
  
}


