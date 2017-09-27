/** Polinomio.cpp - Implementación de la clase Polinomio
 */
#include <iostream>
using namespace std;	/* cout, ostream */
#include "Polinomio.h"
#include "myfecha.h"
#define maximo(a,b)	((a>b)?a:b)
Polinomio::Polinomio(int intGrado,Rac *RacPt):
grado(intGrado),A(RacPt){ }

Polinomio& Polinomio::operator+(Polinomio& PolObj){
	int grad=maximo(grado,PolObj.grado);
	Polinomio ResPol(grad,new Rac[grad+1]);
	if(grado==grad){/*si el obj implicito es el de mayor grado*/
		for(int i=0;i<grado+1;i++){
			(ResPol.A+i)->n=(A+i)->n;
			(ResPol.A+i)->d=(A+i)->d;
		}
	}else{/*si el segundo operando es el de mayor grado*/
		for(int i=0;i<PolObj.grado+1;i++){
			(ResPol.A+i)->n=(PolObj.A+i)->n;
			(ResPol.A+i)->d=(PolObj.A+i)->d;
		}
	}
	if(grado<=grad){/*objeto implicito es el polinomio de menor grado*/
		for(int i=0;i<grado+1;i++){
			*(ResPol.A+i)=*(ResPol.A+i)+*(A+i);
		}
	}else{
		for(int i=0;i<ResPol.grado+1;i++){
			*(ResPol.A+i)=*(ResPol.A+i)+*(PolObj.A+i);
		}
	}
	return ResPol;
}
Polinomio& Polinomio::operator-(Polinomio& PolObj){//Stub
	return PolObj;
}
Polinomio& Polinomio::operator*(Polinomio& PolObj){//Stub
	return PolObj;
}
Polinomio& Polinomio::operator/(Polinomio& PolObj){//Stub
	return PolObj;
}
ostream& operator<<(ostream& ostreamOut,Polinomio& Polinomio1){
  for(int i=0;i<Polinomio1.grado+1;i++){
  	ostreamOut<<"\t"<<(Polinomio1.A+i)->n<<"/"<<(Polinomio1.A+i)->d;
  }
  return ostreamOut;
}
