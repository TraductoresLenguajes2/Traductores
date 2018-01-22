#ifndef _TABLASIMBOLOS
#define _TABLASIMBOLOS

#include <list>
#include <iostream>
#include <string>

using namespace std;

const int TAM= 211;

class ElementoTabla{
public:
	string simbolo;
	char tipo;

	virtual bool esVariable(){return false;}
	virtual bool esVarLocal(){return false;}
	virtual bool esFuncion(){return false;}

	virtual void muestra() {};
};

class Variable: public ElementoTabla{
protected:
	bool local;
public:
	string ambito;
/*	Variable(string simbolo, string ambito, char tipo){
		local= ambito.compare("")==0;
		this->simbolo= simbolo;
		this->tipo= tipo;
	}*/

	Variable(char tipo, string simbolo, string ambito){
		this->tipo= tipo;
		this->simbolo= simbolo;
		this->ambito= ambito;
		this->local= (this->ambito.compare("") != 0) ;
	}

	bool esVarLocal(){
		return local;
	}
	bool esVariable(){
		return true;
	}

	void muestra(){
		cout << "Variable: " << simbolo << " tipo= " << tipo;

		if (local) cout << " local " << endl;
		else cout << " global " << endl;
	}
};

class Funcion: public ElementoTabla{
protected:
public:
	string parametros;
	bool esFuncion(){return true;}

	Funcion(char tipo, string simbolo, string parametros){
		this->simbolo= simbolo;
		this->tipo= tipo;
		this->parametros= parametros;
	}

	void muestra(){
		cout << "Funcion: " << simbolo << " tipo= " << tipo << " Parametros= " << parametros << endl;
	}
};

class DefVar;
class DefFunc;
class Parametro;

class TablaSimbolos{
protected:
	list <ElementoTabla*> tabla[TAM];
	int dispersion(string simbolo);
public:
	Variable *varLocal;
	Variable *varGlobal;
	Funcion *funcion;

	list <string> *listaErrores;
	
	TablaSimbolos(list <string> *listaErrores){
		this->listaErrores= listaErrores;
	}

	void agrega( ElementoTabla *elemento);
	void muestra();

	bool varGlobalDefinida(string simbolo);
	bool funcionDefinida(string simbolo);
	bool varLocalDefinida(string variable, string funcion);
	void buscaIdentificador(string simbolo);
	void buscaFuncion(string simbolo);

	void agrega( DefVar *defVar);
	void agrega( DefFunc *defFunc);
	void agrega( Parametro *parametros);
	
};

#endif