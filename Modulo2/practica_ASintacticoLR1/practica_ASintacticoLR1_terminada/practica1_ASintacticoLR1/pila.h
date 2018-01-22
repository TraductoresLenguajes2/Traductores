#ifndef _PILA
#define _PILA

#include <list>
#include <iostream>
#include <string>

using namespace std;


class Pila{

   private:      
      list <int> lista;      
      
   public:      
      void push( int x);
      int top();
      int pop();
      void muestra();
};


#endif
