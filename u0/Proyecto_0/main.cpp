/** main.cpp - driver de prueba para la clase struct fecha y 
 *  de las clases Expresion, Box, BoxStringEqual, 
  * ..., ExpresionASimplificar.
 */
#include <iostream>
#include <stdio.h>
using namespace std;	/* string, cout, endl */

#include <windows.h>

#include "myfecha.h"
#include "Expresion.h"
#include "Polinomio.h"
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
	cout<<"rac1="<<endl<<rac1;
	cout<<"rac1 simplificado="<<endl;
	ExpresionASimplificar EAS1(new BoxRac(&rac1));
	EAS1.print();cout<<endl;
	
	Rac rac2;rac2.n=96;rac2.d=128;
	cout<<"rac2="<<endl<<rac2;
	rac2.set_mcd();
	cout<<"rac2 simplificado="<<endl;
	ExpresionASimplificar EAS2(new BoxRac(&rac2));
	EAS2.print();cout<<endl;
	
	Rac rac3=rac1*rac2;
//	cout<<"rac3="<<endl<<rac3;
	
//	Expresion E(new BoxRac(&rac1),new BoxStringOperator('*'),new BoxRac(&rac2),new BoxRac(&rac3));
//	E.print();
	Rac rac4(64,256);
	cout<<"rac4="<<endl;
	ExpresionASimplificar EAS4(new BoxRac(&rac4));
	EAS4.print();
	void driverPolinomio(void);
	cout<<"\n";
	driverPolinomio();
	

	return 0;
}//end main()

void driverPolinomio(void){
  Rac *unRacPt=new Rac[3];
  //cout<<"SO FAR, SO GOOD\n";
  *(unRacPt+0)=Rac(5,20);	/* a_{2} */
  *(unRacPt+1)=Rac(7,2);	/* a_{1} */
  *(unRacPt+2)=Rac(18,5);	/* a_{0} */
  /*usamos constructor Polinomio(int,Rac*)*/
  Polinomio Polinomio1(2,unRacPt); 
  /*Polinomio1 es de grado 2 con coeficientes Rac a_{0} a_{1} a_{2}*/
  cout<<"Polinomio1 ="<<endl;
  cout<<Polinomio1<<endl;
  Polinomio Polinomio2=Polinomio1+Polinomio1;
  cout<<"Polinomio1 + Polinomio1 ="<<endl;
  cout<<Polinomio2<<endl;
}



















