/** main.cpp - driver de prueba para la clase struct fecha.
 */
#include <iostream>
#include <stdio.h>
using namespace std;	/* string */
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
	printf("%s 14 de agosto de 2017\n",get_dia(0));
	Fecha *F=get_Fecha(20170817);
	F->set_dia();
	F->to_string_Pt();
	cout<<" ("<<F->dia<<")"<<endl;
	return 0;
}
