/** diadelasemana.cpp
 * Implementación de la clase sin secciones privadas (struct) Fecha.
 */
#include <iostream>
//#include <stdlib.h>	/* malloc() */
#include <windows.h>
using namespace std;	/* cout */
#include "myfecha.h"

#include "Expresion.h"


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

fecha *get_Fecha(int intFecha){// Tambien se puede usar Fecha* como tipo de retorno
	struct MyUtil{
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

void Rac::simplificar(){
	n=n/mcd;
	d=d/mcd;
}


//void Rac::set_mcd(){
//	int M,N,tmp;
//	if((n!=0)&&(d!=0)){/* Algoritmo de Euclides */
//		if(n>d){
//			M=n;N=d;
//		}else{
//			M=d;N=n;
//		}
//		while((tmp=M%N)!=0){ /* M = QN + r */
////			M=M/N;
////			N=tmp;
//			M=N;N=tmp;
//		}/*cuando este while termina, en N se tiene el mcd*/
//	}else{
//		N=1;
//	}
////	cout<<"El mcd de "<<n<<" y "<<d<<" es "<<N<<endl;
//	mcd=N;
//}

/**
 *  Sobrecarga del operador << 
 */
ostream& operator<<(ostream& ostreamOut,Rac& RacObj){
	ostreamOut<<" "<<RacObj.n<<" "<<endl;
	ostreamOut<<"----"<<endl;
	ostreamOut<<" "<<RacObj.d<<endl;
	return ostreamOut;	
}

Rac& Rac::operator*(Rac& RacObj){
	Rac RacResult;
	RacResult.n=n*RacObj.n;
	RacResult.d=d*RacObj.d;
	RacResult.set_mcd();
	RacResult.simplificar();
	Expresion E(new BoxRac(this),new BoxStringOperator('x'),
				new BoxRac(&RacObj),new BoxRac(&RacResult));
	E.print();
	return RacResult;
}

Rac::Rac(int intNum,int intDen):n(intNum),d(intDen){
	set_mcd();
}
Rac::Rac(){
}


void Rac::set_mcd(){
	int M,N,tmp;
	if(n>d){
		M=n;N=d;
	}else{
		M=d;N=n;
	}
	while((tmp=M%N)!=0){ /* M = QN + r */
		M=N;
		N=tmp;
	}/*cuando este while termina, en N se tiene el mcd*/
	mcd=N;
}
Rac& Rac::operator+(Rac& RacObj){
	Rac RacResult;
	RacResult.n=n*RacObj.d+d*RacObj.n;
	RacResult.d=d*RacObj.d;
	RacResult.set_mcd();
	RacResult.simplificar();
	//Expresion E(new BoxRac(this),new BoxStringOperator('+'),
	//			new BoxRac(&RacObj),new BoxRac(&RacResult));
	//E.print();
	return RacResult;
}
