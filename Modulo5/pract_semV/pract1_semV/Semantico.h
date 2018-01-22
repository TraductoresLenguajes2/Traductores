#ifndef _SEMANTICO
#define _SEMANTICO
#include "arbolSintactico.h"
#include "tablaSimbolos.h"

class Semantico{
protected:
		list <string> listaErrores;
		Nodo *arbol;
public:


	void muestraErrores(){
		if (listaErrores.size() == 0) return;

		list<string>::iterator it;
		string cad;
		cout << endl << "Errores Semanticos" << endl << endl;
		for (it= listaErrores.begin(); it != listaErrores.end(); it++){
			cad= *it;
			cout << cad << endl;
		}

	}

	bool existenErrores(){
		return listaErrores.size() > 0;
	}

};

#endif