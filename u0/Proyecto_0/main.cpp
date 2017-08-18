#include <iostream>
#include <stdio.h>
struct fecha{
	int d,m,a;	/* dia, mes, anio */
};
typedef struct fecha Fecha;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
char *get_dia(int intNumDia);
Fecha *get_Fecha(int intFecha);

int main(int argc, char** argv) {
	printf("%s 14 de agosto de 2017",get_dia(0));
	Fecha *F=get_Fecha(20170817);
	return 0;
}
