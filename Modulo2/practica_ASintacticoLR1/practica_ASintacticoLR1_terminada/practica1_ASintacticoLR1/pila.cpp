#include "pila.h"
#include "lexico.h"
#include <sstream>


  void Pila::push( int x){
       lista.push_front(x);
  }
       
 int  Pila::pop(){

     int x= *lista.begin();
     lista.erase ( lista.begin() );
     
     return x;
  }

   int Pila::top(){
     return *lista.begin();     
  }
  
  void Pila::muestra(){

     list <int>::reverse_iterator  it;

     cout << "Pila: ";   
     
     for (it= lista.rbegin(); it != lista.rend(); it++){
         cout << (*it) << " ";         
     } 
  
     cout << endl;
  }
