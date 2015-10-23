#include <iostream>
#include <string>
#include <vector>
#include <ostream>
using namespace std;
#include "Boleto.h"
#define SIN_ARGS
//#define CON_ARGS
vector<string> MItem;
vector<string> Evento;
vector<Bol *> B;
Fecha *FECHA;
int cont=2;

//void mostrar_vector(vector<Bol *>);
//void mostrar_Boleto(Boleto *);
void agregar(int, Boleto *);//Note el uso de referencia
string ingresar_nombre();
void agregar(Bol *);//Note el uso de referencia
void agregar(vector<Bol *>&, int, Boleto *);//Note el uso de referencia
void resumen(int);
void resumen(vector<Bol *>, int);
int mostrar_menu();
void procesar_comandos();
void procesar_comandos(vector<Bol *>);
void generar_Boleto();
void generar_Boleto(vector<Bol *>);
void presentar_Resumen();
void presentar_Resumen(vector<Bol *>);
void crear_Evento();
void crear_Evento(vector<Bol*>&, vector<string>&);

int main(){
  string evento3="Agregar Evento";
  MItem.push_back("Generar Boleto");
  MItem.push_back(evento3);
  MItem.push_back("Presentar Resumen");
  MItem.push_back("Salir");
  FECHA=new Fecha(10,10,2015);
  string evento1="Guerra de Robots";
  string evento2="Eleccion de Representantes al CTCE UPIITA";
  Evento.push_back(evento1);
  Evento.push_back(evento2);
  B.push_back(new Bol());
  B.push_back(new Bol());
  B[0]->set_evento(evento1);
  B[1]->set_evento(evento2);
  
#ifdef CON_ARGS
  procesar_comandos(B);
#endif
#ifdef SIN_ARGS
  procesar_comandos();
#endif
  
  return 0;
}//end main()

int mostrar_menu(){
  int cho;
  do{
  cout << endl;
  cout << "Teclee un numero que corresponda a un elemento del siguiente menu:" << endl;
  for(int i=0; i<MItem.size(); ++i)
    cout << i << " " << MItem[i] << endl;
  cout << "Teclee el numero de la opcion elegida: ";
  cin >> cho;
  }while((cho<0)||(cho>=MItem.size()));
  return cho;
}
void procesar_comandos(){
  int elec;
  do{
    elec=mostrar_menu();
    switch(elec){
      case 0:{generar_Boleto();break;}
      case 1:{cin.ignore(500, '\n');//crear_Evento();
crear_Evento();
cout << "Despues de crear_Evento():B.size()="<<B.size() << endl;
      break;}
      case 2:{presentar_Resumen();break;}
      default:{break;}
    };
  }while(elec!=MItem.size()-1);
}
void procesar_comandos(vector<Bol *> B){
  int elec;
  do{
    elec=mostrar_menu();
    switch(elec){
      case 0:{generar_Boleto(B);break;}
      case 1:{cin.ignore(500, '\n');//crear_Evento(B, Evento);
crear_Evento();
cout << "Despues de crear_Evento():B.size()="<<B.size() << endl;
      break;}
      case 2:{presentar_Resumen(B);break;}//Para evitar SEGFAULT hay que llamar a presentar_Resumen()
                                          //solo si para todos los eventos hay al menos un Boleto generado
                                          // o mas bien en presentar_Resumen() antes de imprimir 
                                          //la info del cada evento asegurarse de que hay al menos un boleto
                                          //generado por el evento.
      default:{break;}
    };
  }while(elec!=MItem.size()-1);
}
void presentar_Resumen(){
  resumen(Evento.size());
}
void presentar_Resumen(vector<Bol *>P){
  resumen(P, Evento.size());
}

int Boleto::consecutivo=0;
Boleto::Boleto(Fecha *fec):Producto(fec){
  consecutivo++;
}
void Bol::set_evento(string evt){
  evento=evt;
}


string ingresar_nombre(){
  string nuevoevento;
  cout<<"Ingrese el nombre de su evento:";
  getline(cin,nuevoevento);
  return nuevoevento;
}
void agregar(Bol *B){
  int a1=Evento.size();
  string nuevoevento="";
  do{
    nuevoevento=ingresar_nombre();
  }while(nuevoevento=="");
  Evento.push_back("Regresar a Menu anterior");
  Evento[a1-1]=nuevoevento;
  (B+a1-1)->set_evento(nuevoevento);
}
void agregar(int index, Boleto *b){
  cout << "index=" << index <<"B.size()="<< B.size()<<" HERE\n";
  b->numdbol=B[index]->V.size()+1;
  cout << "AFTER\n";
  B[index]->V.push_back(b);
}
/**
 @param index: indice que corresponde al evento para el cual 
 se va a agregar un Boleto en el vector<Boleto*> V del 
 index-esimo objeto de clase Bol.
 */
void agregar(vector<Bol *>&P, int index, Boleto *b){
  cout << "index=" << index <<"P.size()="<< P.size()<<" HERE\n";
  b->numdbol=P[index]->V.size()+1;
  cout << "AFTER\n";
  P[index]->V.push_back(b);
}
#ifdef TERCERA_VARIANTE
void generar_Boleto(){
  int M;
  Boleto *b;
  cout << "Elija el evento:" << endl;
  for(int i=0; i<Evento.size(); ++i)
    cout << i << " " << Evento[i] << endl;
  cout << "Evento elegido: ";
  cin >> M;
  b=new Boleto(FECHA);
  agregar(M, b);
}
#endif /* TERCERA_VARIANTE */
#ifndef TERCERA_VARIANTE
void generar_Boleto(){
  int M;
  Boleto *b;
  cout << "Elija el evento:" << endl;
  for(int i=0; i<Evento.size(); ++i)
    cout << i << " " << Evento[i] << endl;
  cout << "Evento elegido: ";
  cin >> M;
  b=new Boleto(FECHA);
  agregar(M, b);
}
#endif /* TERCERA_VARIANTE */
void generar_Boleto(vector<Bol *> P){
  int M;
  Boleto *b;
  cout << "Elija el evento:" << endl;
  for(int i=0; i<Evento.size(); ++i)
    cout << i << " " << Evento[i] << endl;
  cout << "Evento elegido: ";
  cin >> M;
  b=new Boleto(FECHA);
  agregar(P, M, b);
}

ostream& operator<<(ostream& out, Fecha& f){
    out << f.dia << "/" << f.mes << "/" << f.anio;
    return out;
}

void resumen(int n){
  cout <<"/------------------------------------------------------------/\n";
  cout <<"RESUMEN\n";
  cout << Empresa<string>::str_empresa << endl;
  for(int k=0; k<n; ++k){
    if(B[k]->V.size()){
      cout << "Boletos emitidos para el evento (" << *((*(B[k]->V[0])).f) << ") \"" 
           << B[k]->evento << "\": " << B[k]->V.size() << endl;
    }
  }
  cout << "Total de Boletos emitidos: " << Boleto::get_consecutivo() << endl;
  cout <<"/------------------------------------------------------------/\n";
}
/**
  @param n: el numero de eventos para los cuales hay series de boletos.
 */
void resumen(vector<Bol *>P, int n){
  cout <<"/------------------------------------------------------------/\n";
  cout <<"RESUMEN\n";
  cout << Empresa<string>::str_empresa << endl;
  for(int k=0; k<n; ++k){
    if(P[k]->V.size()){
      cout << "Boletos emitidos para el evento (" << *((*(P[k]->V[0])).f) << ") \"" 
           << P[k]->evento << "\": " << P[k]->V.size() << endl;
    }
  }
  cout << "Total de Boletos emitidos: " << Boleto::get_consecutivo() << endl;
  cout <<"/------------------------------------------------------------/\n";
}

void crear_Evento(){
  string cad;
  cout << "Teclea el nombre del evento a crear: ";
  getline(cin, cad);
  B.push_back(new Bol());
  //B[B.size()-1]->set_evento(cad);
  B[cont]->set_evento(cad);
  Evento.push_back(cad);
  cont++;
}
void crear_Evento(vector<Bol*>&KB, vector<string>&EVT){
  string cad;
  cout << "Teclea el nombre del evento a crear: ";
  getline(cin, cad);
  KB.push_back(new Bol());
  KB[KB.size()-1]->set_evento(cad);
  EVT.push_back(cad);
}
