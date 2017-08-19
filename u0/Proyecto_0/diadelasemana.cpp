#include <iostream>
#include <stdlib.h>	/* malloc() */
using namespace std;	/* cout */
#include "myfecha.h"
char *D[]={(char*)"Lunes",(char*)"Martes",(char*)"Miercoles",
(char*)"Jueves",(char*)"Viernes",(char*)"Sabado",(char*)"Domingo"};
void Fecha::to_string_Pt(){
	cout<<d<<"/"<<m<<"/"<<a;
}

string DIA[]={"Lunes","Martes","Miercoles","Jueves","Viernes",
"Sabado","Domingo"};
/*agosto de 2017 SOLO PARA ESTE MES*/
void Fecha::set_dia(){
	dia=DIA[(d+7)%7];
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
		case 2:{
			return D[2];
			break;
		}
		case 3:{
			return D[3];
			break;
		}
		case 4:{
			return D[4];
			break;
		}
		case 5:{
			return D[5];
			break;
		}
		case 6:{
			return D[6];
			break;
		}
		default:{
			return (char*)"NO DIA";
			break;
		}
	}
}

Fecha *get_Fecha(int intFecha){/*20170818*/
	class MyUtil{
	public:
		/**
		* @return: Decena y Unidad de un numero entero
		*/
		static int DyU(int num){
			int tm=100*(num/100);
			return num-tm;
		}
	};//end class MyUtil
	//Fecha *R=(Fecha*)malloc(sizeof(Fecha));
	Fecha *R=new Fecha();
	R->d=MyUtil::DyU(intFecha);
	R->m=MyUtil::DyU(intFecha/100);
	R->a=intFecha/10000;
	return R;
}


