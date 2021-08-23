#include "Lexico.h"

Lexico::Lexico(){
	
}

void Lexico::setMyChain(const string& cadena)
{
	myChain = cadena;
	size = myChain.length();
}

void Lexico::Type()
{
	switch (state) {
	case SymbolType::Entire:
		cout << "Entero";
		break;
	case SymbolType::Lyrics:
		cout << "Letra";
		break;
	case SymbolType::Point:
		cout << "Punto";
		break;
	case SymbolType::Real:
		cout << "Real";
		break;
	case SymbolType::Invalid:
		cout << "Invalido";
		break;
	}
	cout << endl;
	
}

/// Inicio del automata
void Lexico::analyze()
{
	state = 0;
	index = 0;
	next = true;
	final = false;
	result = "";

	while (final == false) {
		
			if (next) {
				c = nextSymbol();
			}

			if (final == true) {
				cout << "Final de la cadena" << endl;
				break;
			}

			if (isNum(c) and state == 0) {
				state = 1;
				result += c;
				next = true;
			}
			else if (isNum(c) and state == 1) {
				result += c;
			}
			else if ((isLyrics(c) or c == 164) and state == 0) {
				state = 2;
				result += c;
				next = true;
			}
			else if ((isLyrics(c) or c == 164) and state == 2) {
				state = 2;
				result += c;
				next = true;
			}
			else if (isSpace(c)) {

			}
			else if (isPoint(c) and state == 1) {
				state = 3;
				result += c;
			}
			else if (isNum(c) and state == 3) {
				state = 4;
				result += c;
			}
			else if (isNum(c) and state == 4) {
				result += c;
			}
			else if (state == -1) {
				next = true;
				result += c;
			}
			else if (isNum(c) or isLyrics(c) and state != 3) {
				next = false;
				behind();
			}
			else {
				cout << "Se  obtuvo: " << result << " ";
				cout << chainResult() << endl;
				result = "";
				cout << c << ": Invalido, interrumpio la secuecia" << endl;
				result += c;
				state = -1;
			}

			if (next) {
				cout << c << ": ";
				Type();
			}

			

	}

	cout << "Se  obtuvo: " << result << " ";
	cout << chainResult() << endl;

}


char Lexico::nextSymbol()
{
	if (index == size) {
		next = false;
		final = true;
	}
	else {
		return myChain[index++];
	}
	
}

bool Lexico::isSpace(const char& c)
{
	return c== ' ' || c == '\t';
}

bool Lexico::finaly()
{
	
	return false;
}

bool Lexico::isNum(const char& c)
{
	return isdigit(c);
}

bool Lexico::isLyrics(const char& c)
{
	return isalpha(c) || c == 'ñ' || c== 'Ñ';
}

bool Lexico::isPoint(const char& c)
{
	return c== '.';
}

string Lexico::chainResult()
{
	string cadena;
	switch (state) {
	case SymbolType::Entire:
		cout << "Entero";
		break;
	case SymbolType::Lyrics:
		cout << "Letras";
		break;
	case SymbolType::Point:
		cout << "Punto";
		break;
	case SymbolType::Real:
		cout << "Real";
		break;
	case SymbolType::Invalid:
		cout << "Invalido";
		break;
	default:
		cout << "Invalido";
		break;
	}

	return cadena;
}

void Lexico::behind()
{
	cout << "Se  obtuvo: " << result << " ";
	cout << chainResult() << endl;
	result = "";
	cout << c << ": Interrumpio la secuecia, vuelve al estado inicial" << endl;
	state = 0;
	
}
