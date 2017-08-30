#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>
#include "Boleto.h"
void mostrar_vector(vector<Bol*> Vec);
void agregar(Bol *P, int index, Bol *p); 
/*
"En el laboratorio el fracaso es positivo, si siempre
 haces lo que sabes que funciona, eres demasiado 
 conservador." James Gosling
*/
const string upiita="UPIITA S.A. DE C.V.";
string evento1="Guerra de Robots";
string evento2="Eleccion de representantes al CTCE";
vector<Boleto*> VecG;
vector<Boleto*> VecE;


/* La variable de clase (static) se debe inicializar 
   en alcance de archivo. */
string Boleto::empresa=upiita;
int Boleto::consecutivo=0;

int main(int argc, char** argv) {
	Bol *P=new Bol[2];
	Bol *p;
	
	p=new Boleto();
	agregar(P,0,p);
	
	p=new Boleto();
	agregar(P,0,p);
	
	string event="Guerra de Robots";
	//P[0].set_evento(event);
	P->set_evento(event);
	event="Eleccion de Representantes al CTCE";
	P[1].set_evento(event);
	mostrar_vector(P[0].V);
	
	return 0;
}//

void agregar(Bol *P, int index, Bol *p){
	p->set_numdbol(P[index].V.size()+1);
	P[index].V.push_back(p);
}
void Bol::set_evento(string& evt){
	evento=evt;
}
//Solo para poder enlazar
void Bol::set_numdbol(int a){
}
//Solo para poder enlazar
int Bol::get_numdbol(){
	return -1;
}

void mostrar_datos_boleto(Bol *b){
	cout << b->get_numdbol() << " " << b->evento << endl;
}

void mostrar_vector(vector<Bol*> Vec){
	for(int i=0; i<Vec.size(); ++i)
	  mostrar_datos_boleto(Vec[i]);
}
