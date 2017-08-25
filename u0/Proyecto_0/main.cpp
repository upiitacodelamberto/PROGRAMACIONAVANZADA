/** main.cpp - driver de prueba para la clase struct fecha.
 */
#include <iostream>
#include <stdio.h>
using namespace std;	/* string, cout, endl */
#include "myfecha.h"
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
char *get_dia(int intNumDia);
/**
 * Devuelve un apuntador a Fecha.
 * @param intFecha: debe representar una fecha de acuerdo con el formato 
 *                  yyyymmdd, por ejemplo, 20170819 representa 19 de agosto 
 *                  de 2017.
 */
Fecha *get_Fecha(int intFecha);

int main(int argc, char** argv) {
	printf("%s 23 de agosto de 2017\n",get_dia(2));
	Fecha *F=get_Fecha(20170823);
	F->set_dia();
	F->to_string_Pt();
	cout<<" ("<<F->dia<<")"<<endl;
	
	Rac rac1;rac1.n=30;rac1.d=60;rac1.mcd=30;
	cout<<rac1;
	rac1.simplificar();
	cout<<rac1;
	
	Rac rac2;rac2.n=64;rac2.d=128;
	cout<<rac2;
	rac2.set_mcd();
	rac2.simplificar();
	cout<<rac2;
	Rac rac3=rac1*rac2;
	cout<<rac3;
	
	return 0;
}
