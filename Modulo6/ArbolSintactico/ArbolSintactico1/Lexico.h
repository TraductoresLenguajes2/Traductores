#ifndef _LEXICO
#define _LEXICO

#include <iostream>
#include <string>
using namespace std;

class TipoSimbolo{
public:
 static const int ID= 0;
 static const int ENTERO= 50;
 static const int OPSUMA= 51;
 static const int PESOS= 1;       
};


class Lexico{
      private:
       string fuente;
       int ind;       
              
      public:
       char simbolo;
       int tipo;
             
       Lexico(string fuente);             
       Lexico();
       
       void entrada(string fuente);       
       
       int sigSimbolo();
       bool terminado();
};


#endif