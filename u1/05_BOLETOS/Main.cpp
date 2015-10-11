#include <iostream>
#include <string>
#include <vector>
#include <ostream>
using namespace std;

#include "Boleto.h"

int Boleto::consecutivo=0;
void agregar(Bol *P, int index, Boleto *b);
void mostrar_vector(Bol *P);

int main(){
  Bol *B=new Bol[2];
  Boleto *b;

  string event;
  event="Guerra de Robots";

  b=new Boleto(event);
  agregar(B, 0, b);
  b=new Boleto(event);
  agregar(B, 0, b);
  b=new Boleto(event);
  agregar(B, 0, b);
  b=new Boleto(event);
  agregar(B, 0, b);

  event="Eleccion de Representantes al CTCE de UPIITA";
  b=new Boleto(event);
  agregar(B, 1, b);
  b=new Boleto(event);
  agregar(B, 1, b);
  b=new Boleto(event);
  agregar(B, 1, b);

  mostrar_vector(B);
  mostrar_vector(B+1);

  return 0;
}

Boleto::Boleto(string e):Bol(e){
  consecutivo++;
}

void agregar(Bol *P, int index, Boleto *b){
  b->numdbol=(P+index)->V.size()+1;
  (P+index)->V.push_back(b);
}

void mostrar_vector(Bol *P){
  for(int i=0; i<P->V.size(); ++i)//P->V[i] es Boleto*, *(P->V[i]) es Boleto, (*(P->V[i])).evento es string
    cout << P->V[i]->numdbol << " " 
         //<< P->V[i]->evento << " " //Se puede usar esta o la siguiente linea.
         << (*(P->V[i])).evento << ", "
         << (*(P->V[i])).empresa << " " << endl;
//         << *((*(P->V[i])).f) << endl;
  cout <<  endl;
}
