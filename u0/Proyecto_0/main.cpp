#include <iostream>
#include <stdio.h>
using namespace std;	/* string */
#include "myfecha.h"
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
char *get_dia(int intNumDia);
Fecha *get_Fecha(int intFecha);

int main(int argc, char** argv) {
	printf("%s 14 de agosto de 2017\n",get_dia(0));
	Fecha *F=get_Fecha(20170817);
	F->set_dia();
	F->to_string_Pt();
	cout<<" ("<<F->dia<<")"<<endl;
	return 0;
}
