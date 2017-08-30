#include <iostream>
#include <string>
#include <vector>
#include <ostream>
using namespace std;

class Boleto;
class Bol{
public:
  string evento;
  void set_evento(string);
  vector<Boleto*> V;
};//end class Bol

template <typename T> class Empresa{
public:
  static T str_empresa;
};//end template Empresa
template <typename T>
T Empresa<T>::str_empresa="UPIITA S.A. de C.V.";
/**
 La plantilla anterior y la inicializacion de su atributo 
 public static son para emular el __attribute__((weak)) 
 de gcc en linux. Solo que aqui el simbolo fuerte se debe 
 definir \underline{dentro de una funcion} asi:
 Empresa<string>::str_empresa="Nombre de otra empresa";
 en este o en otro archivo (en cuyo caso este template y 
 la inicializacion de su atributo public static debe 
 ponerse en un archivo de cabecera e incluirlo en el otro 
 archivo).
 */

class Fecha;
class Producto{
public:
  string NombreDEmpresa;
  //Fecha del evento para el cual se vende el Producto 
  //(en este caso un Boleto)
  Fecha *f;
  Producto():NombreDEmpresa(Empresa<string>::str_empresa){ }
  Producto(Fecha *fech):f(fech), 
  NombreDEmpresa(Empresa<string>::str_empresa){ }
  void set_fecha(Fecha *f){
    this->f=f;
  }
};//end class Producto

class Boleto : public Producto{
  static int consecutivo;
public:
  int numdbol;
  Boleto(Fecha *F);
  static int get_consecutivo(){
    return consecutivo;
  }
};//end class Boleto

class Fecha{
public:
  int dia, mes, anio;
  Fecha(int a, int b, int c):dia(a),mes(b),anio(c){ }
  friend ostream& operator<<(ostream& out, Fecha& f);
};//end class Fecha

void mostrar_vector(Bol *);
//void mostrar_Boleto(Boleto *);
void agregar(Bol *, int, Boleto *);
void resumen(Bol *, int);

int main(){
  //Primero un evento para hoy sabado 10 de octubre
  Fecha *F=new Fecha(10, 10, 2015);
  //Bol *B=new Bol();
  Bol *B=new Bol[2];   //Por ahora, desde aqui fijamos B solo para dos eventos.
  string event="Guerra de Robots";
  B->set_evento(event);

  Boleto *b;
  b=new Boleto(F);
  agregar(B, 0, b);
  mostrar_vector(B);

  //Se puede no usar agregar(), pero se debe 
  //crear un nuevo Boleto y hacer las dos operaciones
  //que se hacen en agregar()
  b=new Boleto(F);
  b->numdbol=B->V.size()+1;
  B->V.push_back(b);
  mostrar_vector(B);

  b=new Boleto(F);
  agregar(B, 0, b);
  mostrar_vector(B);


  //Ahora otro evento para el 1 de noviembre
  event="Eleccion de Representantes al CTCE";
  (B+1)->set_evento(event);
  F=new Fecha(1, 11, 2015);

  b=new Boleto(F);
  agregar(B, 1, b);

  b=new Boleto(F);
  agregar(B, 1, b);

  b=new Boleto(F);
  agregar(B, 1, b);

  b=new Boleto(F);
  agregar(B, 1, b);
  mostrar_vector(B+1);

  resumen(B, 2);
  return 0;
}//end main()

int Boleto::consecutivo=0;
Boleto::Boleto(Fecha *fec):Producto(fec){
//  set_fecha(fec);
  consecutivo++;
}
void Bol::set_evento(string evt){
  evento=evt;
}

void mostrar_vector(Bol *P){
  for(int i=0; i<P->V.size(); ++i)
    cout << P->V[i]->numdbol << " " << P->evento << " "
         << (*(P->V[i])).NombreDEmpresa << " " 
         << *((*(P->V[i])).f) << endl;
  cout <<  endl;
}
//void mostrar_Boleto(Boleto *);

/**
 @param index: indice que corresponde al evento para el cual 
 se va a agregar un Boleto en el vector<Boleto*> V del 
 index-esimo objeto de clase Bol.
 */
void agregar(Bol *P, int index, Boleto *b){
  b->numdbol=(P+index)->V.size()+1;
  (P+index)->V.push_back(b);
}

ostream& operator<<(ostream& out, Fecha& f){
    out << f.dia << "/" << f.mes << "/" << f.anio;
    return out;
}

/**
  @param n: el numero de eventos para los cuales hay series de boletos.
 */
void resumen(Bol *P, int n){
  cout << Empresa<string>::str_empresa << endl;
  for(int k=0; k<n; ++k){
    cout << "Boletos emitidos para el evento (" << *((*((P+k)->V[0])).f) << ") \"" 
         << (P+k)->evento << "\": " << (P+k)->V.size() << endl;
  }
  cout << "Total de Boletos emitidos: " << Boleto::get_consecutivo() << endl;
}
