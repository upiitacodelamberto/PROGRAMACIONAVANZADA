#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include "Boleto.h"
 
using namespace std;
 
Boleto::Boleto(const string e){
	consecutivo++;numdbol=consecutivo;
    evento=e;
}
/*
Como ejercicio: Escribir una funcion analoga a swap2
que utilice dos referencias a string y probar si 
funciona de forma analoga al caso de swap2.
*/
/*
"En el laboratorio el fracaso es positivo, si siempre
 haces lo que sabes que funciona, eres demasiado 
 conservador." James Gosling
*/
const string upiita="UPIITA S.A. DE C.V.";
string evento1="Guerra de Robots";
string evento2="Eleccion de representantes al CTCE";

void myswap(int a, int b){
	int tmp=a;a=b;b=tmp;
}
void swap1(int *, int *);
void swap2(int&, int&);//Usamos referencias
void mostrar_datos_boleto(Boleto *);
void mostrar_vector(vector<Boleto*>);

vector<Boleto*> VecG;
vector<Boleto*> VecE;

/* La variable de clase (static) se debe inicializar 
   en alcance de archivo. */
string Boleto::empresa=upiita;
int Boleto::consecutivo=0;
                       
int main(int argc, char *argv[])
{
    //Boleto::empresa=upiita; //Esto se DEBE hacer en alcance de archivo!!
                              //(vease la sentencias previas a main())

    /* para llevar la cuenta de boletos emitidos */
    //Boleto::consecutivo=0;  //Esto tambien se DEBE hacerse en alcance de archivo!!
    int A1=10, B1=20;
    myswap(A1,B1);//Paso de argumentos "por valor"
    cout << "A1=" << A1 << ", B1=" << B1 << endl;
    //swap(A1,B1);//Por que esto no produce error?
    //Porque la funcion swap ya existe. Donde esta?
    //#include cstdlib
    
    swap1(&A1, &B1);//PAso de argumentos "por referencia"
    cout << "A1=" << A1 << ", B1=" << B1 << endl;
    cout << "Se resturan A1 y B1 a sus valores originales "
         << "antes de llamar a swap2()" << endl;
    int tmp=A1;A1=B1;B1=tmp;
    swap2(A1, B1);
    cout << "A1=" << A1 << ", B1=" << B1 << endl;

	//Instanciamos cuatro objetos de la clase Boleto
    Boleto C;
    Boleto D=Boleto();
     
    Boleto A(evento1);
    Boleto B(evento1);
/*
    cout << A.consecutivo << " "
         << B.consecutivo << "\n"
         << Boleto::empresa << endl;
	cout << "Objeto A" << A.empresa << endl
	     << A.evento << endl
	     << A.numdbol << endl << endl;
	cout << "Objeto B" << B.empresa << endl
	     << B.evento << endl
	     << B.numdbol << endl;
  */
  //``Seteamos'' los eventos de los objetos C y D 
  C.set_evento(evento1);
  Boleto *p=&D;p->set_evento(evento1);
  //imprimo indice inicial del vector VecG
  cout <<"VecG.size()="<< VecG.size() << endl;
  
  //Declaramos un arreglo de apuntadores a Boleto
  Boleto *ARR[4];
  //Llenamos el arreglo ARR
  ARR[0]=&C;ARR[1]=&D;ARR[2]=&A;ARR[3]=&B;
  
  //Ponemos los Boletos para Guerra de Robots en el vector VecG
  C.set_numdbol(VecG.size()+1);VecG.push_back(&C);
  D.set_numdbol(VecG.size()+1);VecG.push_back(&D);
  A.set_numdbol(VecG.size()+1);VecG.push_back(&A);
  B.set_numdbol(VecG.size()+1);VecG.push_back(&B);
  //Mostramos los Boletos emitidos para Guerra de Robots
  for(int i=0; i<4; ++i)
    mostrar_datos_boleto(ARR[i]);
  //Ahora instaciamos y ponemos en el vector VecE cuatro Boletos
  //para el evento Eleccion de Representantes al CTCE
  Boleto *p1=new Boleto(evento2);
  p1->set_numdbol(VecE.size()+1);VecE.push_back(p1);
  Boleto *p2=new Boleto(evento2);
  p2->set_numdbol(VecE.size()+1);VecE.push_back(p2);
  Boleto *p3=new Boleto(evento2);
  p3->set_numdbol(VecE.size()+1);VecE.push_back(p3);
  Boleto *p4=new Boleto(evento2);
  p4->set_numdbol(VecE.size()+1);VecE.push_back(p4);
  
  cout << endl << "/-----------------------------/"
       << endl;
  //mostramos los Boletos en el vector VecG
  mostrar_vector(VecG);
  cout << endl;
  //mostramos los Boletos en el vector VecE
  mostrar_vector(VecE);
  cout << endl << endl;
  cout << "Cantidad total de boletos: "
       << Boleto::consecutivo << endl;  
#ifdef _WIN32
    system("PAUSE");
#endif
    return EXIT_SUCCESS;
}//end main()

void swap1(int *a, int *b){
	int tmp=*a;*a=*b;*b=tmp;
}

void swap2(int& x, int& y){
	int tmp=x;x=y;y=tmp;
}

void mostrar_datos_boleto(Boleto *bol){
	cout << bol->numdbol << " " << bol->evento << endl;
}

void Boleto::set_evento(string evt){
	evento=evt;
}

void Boleto::set_numdbol(int N){
	numdbol=N;
}

void mostrar_vector(vector<Boleto*> Vec){
	for(int i=0; i<Vec.size(); ++i)
	  mostrar_datos_boleto(Vec[i]);
}
