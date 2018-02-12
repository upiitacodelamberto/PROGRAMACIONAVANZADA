#include <iostream>
#include "Rac.h"
#include "Polinomio.h"
using namespace std; /*cout*/
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	Rac rac1;rac1.n=30;rac1.d=60;rac1.mcd=30;
	Rac rac2=rac1+rac1+rac1;//rac2=rac2+rac1;
	cout<<"rac1="<<endl<<rac1;
	cout<<"mcd="<<rac1.calc_mcd()<<endl;
	rac1.simplificar();
	cout<<"rac1 simplificado="<<endl;
	cout<<rac1;
	cout<<"rac2="<<endl<<rac2<<endl;
	Rac rac3=rac1+rac2;
	cout<<"rac3="<<endl<<rac3<<endl;;
//	cout<<rac1+rac1+rac1;
//	cout<<rac1+rac2;
	
//	Rac *RacPt=new Rac[3];
//	*(RacPt+0)=rac1;
//	*(RacPt+1)=rac2;
//	*(RacPt+2)=rac3;
//	Polinomio P(2,RacPt);
//	cout<<"P="<<endl<<P<<endl;
//	Polinomio Q=P+P; 
//	cout<<"Q="<<endl<<Q<<endl;
	return 0;
}
