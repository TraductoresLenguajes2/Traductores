#include "pila.h"
#include "lexico.h"
#include <sstream>

//***********************************************************************************************************************
//  Elemento Pila
//***********************************************************************************************************************


ElementoPila::ElementoPila(){
	tipo= -1;
}

Estado::Estado(int id):ElementoPila(){
   this->id = id;
   std::stringstream convertStream;
   convertStream << id;
   convertStream >> simbolo;
}

ostream &operator << (ostream &salida, ElementoPila &elementoPila){
   salida << elementoPila.simbolo;
    return salida;
}

Terminal::Terminal(int id):ElementoPila(){
	this->id= id;
	if (id == TipoSimbolo::PESOS ) 
 	   simbolo= "$";
}

Terminal::Terminal(int tipo, char simbolo, int subtipo):ElementoPila(){
	id= tipo;
	this->simbolo= simbolo;
	this->subtipo = subtipo;
}

NoTerminal::NoTerminal(int tipo, string simbolo):ElementoPila(){
	this->id= tipo;
	this->simbolo= simbolo;
	this->tipo = tipo;
}

//***********************************************************************************************************************
//  PILA
//***********************************************************************************************************************

  void Pila::push( ElementoPila* x){
       lista.push_front(x);
  }
       
 ElementoPila * Pila::pop(){

     ElementoPila *elemento= *lista.begin();
     lista.erase ( lista.begin() );
     
     return elemento;
  }

   ElementoPila * Pila::top(){
     return *lista.begin();     
  }
  
  void Pila::muestra(){

//     typename list <ElementoPila*>::reverse_iterator  it;
     list <ElementoPila*>::reverse_iterator  it;

     cout << "Pila: ";   
     
     for (it= lista.rbegin(); it != lista.rend(); it++){
         cout << *(*it) << " ";         
     } 
  
     cout << endl;
  }
