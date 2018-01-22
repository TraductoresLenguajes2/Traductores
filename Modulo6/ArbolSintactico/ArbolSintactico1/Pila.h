#ifndef _PILA
#define _PILA

#include <list>
#include <iostream>
#include <string>



using namespace std;

class Nodo;

class ElementoPila{
private:
public:
	int id;
	int tipo;   //ejem. op multiplicación
	int subtipo;// ejem. * ó /
	string simbolo;
	
	Nodo *nodo;

	ElementoPila();

	virtual bool esEstado(){ return false;}
	virtual bool esTerminal(){ return false;}
	virtual bool esNoTerminal(){ return false;}
		
    //friend ostream &operator << (ostream &salida, ElementoPila &elementoPila);
    
};

class Estado: public ElementoPila{
private:        
public:
	Estado(int id);
	bool esEstado(){ return true;}
};

class Terminal: public ElementoPila{
private:
public:
	Terminal(int id);
	Terminal(int tipo, char simbolo, int subtipo=0);
	bool esTerminal(){ return true;}
};

class NoTerminal: public ElementoPila{
private:
public:
	NoTerminal(int id, string simbolo);
	bool esNoTerminal(){ return true;}
};



class Pila{

   private:      
      list <ElementoPila*> lista;      
      
   public:      
      void push( ElementoPila* x);
      ElementoPila* top();
      ElementoPila* pop();
      void muestra();
};


#endif