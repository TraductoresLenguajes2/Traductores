#include "tablaSimbolos.h"
#include "arbolSintactico.h"


void TablaSimbolos::agrega( DefVar *defVar){	

}

void TablaSimbolos::agrega( Parametro *parametros){
}


void TablaSimbolos::agrega( DefFunc *defFunc){
}

int TablaSimbolos::dispersion(string simbolo){
	unsigned int h=0, g;
	unsigned char c;
	unsigned char alfa= 4;
	
	for (int i=0; i<simbolo.length(); i++){
		c= simbolo[i];
//		h= (h << 4) + c;
		h += alfa*c;
		h= h % TAM;
	}

	return h%TAM;
}

void TablaSimbolos::agrega( ElementoTabla *elemento){
	int ind= dispersion(elemento->simbolo);
	tabla[ind].push_back(elemento);
}

void TablaSimbolos::muestra(){
	list<ElementoTabla*>::iterator it;
	ElementoTabla *elem;

	cout << endl << "*** Tabla de Simbolos ***" << endl;

	for (int i=0; i< TAM; i++){
		if (tabla[i].size() > 0){

			for (it= tabla[i].begin(); it != tabla[i].end(); it++){
				elem= (ElementoTabla *)*it;
				cout << "Lista= " << i << endl;
				elem->muestra();
			}
		}
	}
}

bool TablaSimbolos::funcionDefinida(string funcion){
	int ind= dispersion(funcion);
	list<ElementoTabla*>::iterator it;
	ElementoTabla *elem;

	for (it= tabla[ind].begin(); it != tabla[ind].end(); it++){
		elem= (ElementoTabla *)*it;
		if (elem->esFuncion()) {
			if (elem->simbolo.compare(funcion) == 0) return true;
		}
	}

	return false;
}

bool TablaSimbolos::varGlobalDefinida(string variable){
	int ind= dispersion(variable);
	list<ElementoTabla*>::iterator it;
	ElementoTabla *elem;

	for (it= tabla[ind].begin(); it != tabla[ind].end(); it++){
		elem= (ElementoTabla *)*it;
		if (elem->esVariable() && !elem->esVarLocal()) {
			if (elem->simbolo.compare(variable) == 0) return true;
		}
	}

	return false;
}

bool TablaSimbolos::varLocalDefinida(string variable, string funcion){
	int ind= dispersion(variable);
	list<ElementoTabla*>::iterator it;
	ElementoTabla *elem;

	for (it= tabla[ind].begin(); it != tabla[ind].end(); it++){
		elem= (ElementoTabla *)*it;
		if (elem->esVariable() && elem->esVarLocal()) {
			if (((Variable*)elem)->ambito.compare(funcion) ==0  && elem->simbolo.compare(variable) == 0) return true;
		}
	}

	return false;
}

void TablaSimbolos::buscaIdentificador(string simbolo){
	int ind= dispersion(simbolo);
	list<ElementoTabla*>::iterator it;
	ElementoTabla *elem;

	varGlobal= NULL;
	varLocal= NULL;
	funcion= NULL;

	for (it= tabla[ind].begin(); it != tabla[ind].end(); it++){
		elem= (ElementoTabla *)*it;

		if (elem->simbolo.compare(simbolo) == 0){
			if (elem->esVariable()){
				if (elem->esVarLocal()) varLocal= (Variable*)elem;
				else
					varGlobal= (Variable*)elem;
			}
			else
				funcion= (Funcion*)elem;
		}

	}
	
}


void TablaSimbolos::buscaFuncion(string simbolo){
	int ind= dispersion(simbolo);
	list<ElementoTabla*>::iterator it;
	ElementoTabla *elem;

	varGlobal= NULL;
	varLocal= NULL;
	funcion= NULL;

	for (it= tabla[ind].begin(); it != tabla[ind].end(); it++){
		elem= (ElementoTabla *)*it;

		if (elem->simbolo.compare(simbolo) == 0 && elem->esFuncion()){
				funcion= (Funcion*)elem;
				return;
		}
	}

}

