#include "lexico.h"

  Lexico::Lexico(string fuente){
    ind= 0;                  
//    strcpy(this->fuente, fuente);
      this->fuente= fuente;
  }      

  Lexico::Lexico(){
    ind= 0;                  
    fuente= "";
  }      

int Lexico::sigSimbolo(){  
    //esta función es una versión muy sencilla del siguiente simbolo, en tu compilador deberas modificarla con el
    //código de tu analizador léxico
    
	do{
       simbolo= fuente[ind++];
     } while ( simbolo == ' ');
	
    
    if ( isalpha(simbolo)){
         tipo= TipoSimbolo::ID;
       }
       else if (isdigit(simbolo)){
            tipo= TipoSimbolo::ENTERO;
       }
     else 
    	
	switch ( simbolo ){
       case '\0': tipo= TipoSimbolo::PESOS; simbolo= '$'; break;
       case '+': case '-': tipo= TipoSimbolo::OPSUMA; break;
    }
		
	return tipo;
}

  bool Lexico::terminado(){
//       return ind >= strlen(fuente);
       return ind >= fuente.length();
  }

  void Lexico::entrada(string fuente){
       ind= 0;                  
//       strcpy(this->fuente, fuente);
         this->fuente= fuente;
  }

