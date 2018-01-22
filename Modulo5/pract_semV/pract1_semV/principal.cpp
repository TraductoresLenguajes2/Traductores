#include "arbolSintactico.h"
#include "stdio.h"
#include "semantico.h"

int Nodo::sangria= 0;

Nodo * arbol0(){
	return new DefVar(new Tipo("int"), new Identificador("a", NULL), NULL);
}

Nodo * arbol1(){
	return new DefVar(new Tipo("int"), new Identificador("a", new Identificador("b", new Identificador("c", NULL))), NULL);
}

Nodo * arbol2(){
	return new DefVar(new Tipo("int"), new Identificador("a", new Identificador("b", new Identificador("c", NULL))), new DefVar(new Tipo("float"), new Identificador("x", new Identificador("y", new Identificador("z", NULL))), NULL));
}

Nodo * arbol3(){
	return new DefFunc( new Tipo("int"), new Identificador("suma", NULL), new Parametro( new Tipo("int"), new Identificador("b"), NULL), NULL, NULL);
}

Nodo * arbol4(){
	return new DefFunc( new Tipo("int"), new Identificador("suma", NULL), new Parametro( new Tipo("int"), new Identificador("a"), new Parametro( new Tipo("int"), new Identificador("b"), NULL)), NULL, NULL) ;
}

Nodo * arbol5(){
	return new DefFunc( new Tipo("int"), new Identificador("suma", NULL), new Parametro( new Tipo("int"), new Identificador("a"), new Parametro( new Tipo("int"), new Identificador("b"), NULL)), new Regresa(new Suma("+",new Identificador("a", NULL), new Identificador("b", NULL)) , NULL), NULL) ;
}

Nodo * arbol6(){
	return new DefVar(new Tipo("int"), new Identificador("x", NULL), new DefFunc( new Tipo("int"), new Identificador("f", NULL), NULL, new Asignacion(new Identificador("x", NULL), new Mult("*",new Entero("2"), new Entero("3")) , new Regresa(new Identificador("x", NULL), NULL)), NULL) );
}

Nodo * arbol7(){
	return new DefVar(new Tipo("int"), new Identificador("x", new Identificador("y", NULL)), new DefFunc( new Tipo("float"), new Identificador("f", NULL), NULL, new DefVar(new Tipo("float"), new Identificador("x", new Identificador("y", new Identificador("z", NULL))), new Asignacion(new Identificador("y", NULL), new Real("3.14"), new Asignacion(new Identificador("x", NULL), new Suma("+",new Identificador("y", NULL), new Mult("*",new Identificador("z", NULL), new Real("2.5")) ) , new Regresa(new Identificador("x", NULL), NULL)))), NULL) );
}

Nodo * arbol8(){
	return new DefVar(new Tipo("int"), new Identificador("x", new Identificador("y", NULL)), new DefFunc( new Tipo("int"), new Identificador("f", NULL), NULL, new DefVar(new Tipo("float"), new Identificador("x", new Identificador("y", new Identificador("z", NULL))), new Asignacion(new Identificador("y", NULL), new Real("3.14"), new Asignacion(new Identificador("x", NULL), new Suma("+",new Identificador("y", NULL), new Mult("*",new Identificador("z", NULL), new Real("2.5")) ) , new Regresa(new Identificador("x", NULL), NULL)))), NULL) );
}

Nodo * arbol9(){
	return new DefFunc( new Tipo("int"), new Identificador("f", NULL), NULL, new Asignacion(new Identificador("x", NULL), new Suma("+",new Entero("2"), new Entero("3")) , new Regresa(new Identificador("x", NULL), NULL)), NULL) ;
}

Nodo * arbol10(){
	return new DefVar(new Tipo("float"), new Identificador("x", NULL), new DefFunc( new Tipo("int"), new Identificador("f", NULL), new Parametro( new Tipo("int"), new Identificador("x"), NULL), new DefVar(new Tipo("float"), new Identificador("x", NULL), new Asignacion(new Identificador("x", NULL), new Suma("+",new Entero("2"), new Entero("3")) , new Regresa(new Identificador("x", NULL), NULL))), NULL) );
}

Nodo * arbol11(){
	return new DefVar(new Tipo("float"), new Identificador("x", NULL), new DefFunc( new Tipo("int"), new Identificador("f", NULL), new Parametro( new Tipo("int"), new Identificador("x"), NULL), new DefVar(new Tipo("float"), new Identificador("x", NULL), new Asignacion(new Identificador("x", NULL), new Suma("+",new Entero("2"), new Entero("3")) , new Regresa(new Identificador("x", NULL), NULL))), NULL) );
}


int main(){
	
	Nodo * arbol= arbol10();

	arbol->muestra();



	cin.get();
	
	return 0;
}