/** Polinomio.cpp - Implementación de la clase Polinomio
 */
#include <iostream>
using namespace std;	/* cout, ostream */
#include "Polinomio.h"
Polinomio::Polinomio(int intGrado,Rac *RacPt):
grado(intGrado),A(RacPt){ }

Polinomio& Polinomio::operator+(Polinomio& PolObj){//Stub
	return PolObj;
}
Polinomio& Polinomio::operator-(Polinomio& PolObj){//Stub
	return PolObj;
}
Polinomio& Polinomio::operator*(Polinomio& PolObj){//Stub
	return PolObj;
}
Polinomio& Polinomio::operator/(Polinomio& PolObj){//Stub
	return PolObj;
}
