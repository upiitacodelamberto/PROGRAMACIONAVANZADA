#include <iostream>
#include <stdlib.h>  /*malloc()*/
#include "Calendario.h"
/* run this program using the console pauser or add 
   your own getch, system("pause") or input loop */

using std::cout;
using std::endl;

int main(int argc, char** argv) {
	Calendario *Cal2016=new Calendario(2016);
	cout<<"Los lunes del mes de enero son:"<<endl;
	Cal2016->mostrar_fechas("Lunes","enero");
	cout<<"Los miercoles del mes de febrero son:"<<endl;
	Cal2016->mostrar_fechas("Miercoles","febrero");
#ifdef _WIN32
	system("PAUSE");
#endif
	return 0;
}

