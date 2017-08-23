#include <iostream>
#include <stdlib.h>	/* malloc() */
using namespace std;	/* cout */
#include "myfecha.h"
char *D[]={(char*)"Lunes",(char*)"Martes"};
void Fecha::to_string_Pt(){
	cout<<d<<"/"<<m<<"/"<<a;
}

string DIA[]={"Lunes","Martes","Miercoles","Jueves","Viernes",
"Sabado","Domingo"};
/*agosto de 2017 SOLO PARA ESTE MES*/
void Fecha::set_dia(){
	Fecha::dia=DIA[Fecha::d%7];
}

char *get_dia(int intNumDia){
	switch(intNumDia){
		case 0:{
			return D[0];
			break;
		}
		case 1:{
			return D[1];
			break;
		}
		default:{
			return (char*)"NO DIA";
			break;
		}
	}
}

Fecha *get_Fecha(int intFecha){/*20170818*/
	//Fecha *R=(Fecha*)malloc(sizeof(Fecha));
	Fecha *R=new fecha();
	int tmp=100*(intFecha/100);
	R->d=intFecha-tmp;
	tmp=10000*(intFecha/10000);
	R->m=(intFecha-tmp)/100;
	tmp=1000000*(intFecha/1000000);
	R->a=(intFecha-tmp)/10000;
	return R;
}


