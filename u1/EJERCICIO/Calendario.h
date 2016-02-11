#ifndef CALENDARIO_H
#define CALENDARIO_H
using std::string;

struct SetDInt{
  int n;
  int *intPt;
};
typedef struct SetDInt SetDIntType;

string ARREGLO[][7]={
  {"Jueves","Viernes","Sabado","Domingo","Lunes","Martes","Miercoles"}, /*enero*/
  {"Domingo","Lunes","Martes","Miercoles","Jueves","Viernes","Sabado"}, /*febrero*/
  {"Lunes","Martes","Miercoles","Jueves","Viernes","Sabado","Domingo"}, /*marzo*/
  {"Jueves","Viernes","Sabado","Domingo","Lunes","Martes","Miercoles"}, /*abril*/
  {"Sabado","Domingo","Lunes","Martes","Miercoles","Jueves","Viernes"}, /*mayo*/
  {"Martes","Miercoles","Jueves","Viernes","Sabado","Domingo","Lunes"}, /*junio*/
  {"Jueves","Viernes","Sabado","Domingo","Lunes","Martes","Miercoles"}, /*julio*/
  {"Domingo","Lunes","Martes","Miercoles","Jueves","Viernes","Sabado"}, /*agosto*/
  {"Miercoles","Jueves","Viernes","Sabado","Domingo","Lunes","Martes"}, /*septiembre*/
  {"Viernes","Sabado","Domingo","Lunes","Martes","Miercoles","Jueves"}, /*octubre*/
  {"Lunes","Martes","Miercoles","Jueves","Viernes","Sabado","Domingo"}, /*noviembre*/
  {"Miercoles","Jueves","Viernes","Sabado","Domingo","Lunes","Martes"}  /*diciembre*/
};

class Calendario{
public:
  void mostrar_fechas(string dia,string mes);
  Calendario(int year):numdanio(year){ }
  int get_anio(){
    return numdanio;
  }
  //...
  /**
   Obtiene los numeros de dia de las fechas de los 
   dias d en el mes m.
   */
  SetDIntType* obtener_nums_ddia(string d,string m);
  void print_SetDIntYFecha(string d,string m,SetDIntType* SDI);

  /**
   Obtiene el indice correspondiente al mes month. 
   Si month="enero", debe devolver 0, 
   Si month="febrero", debe devolver 1, 
   Si month="marzo", debe devolver 2, 
   etc.
   */
  int index_delmes(string month);

  /**
   Devuelve el numero de dia de la primera fecha 
   del mes con indice i (devuelto por 
   index_delmes(string month)), en la que el dia 
   es el string day.
   */
  int primera_fecha_delmes(string day,int i);

  /**
    Cumplimenta el SetDIntType al que apunta el apuntador r. 
    Esto es, despues de llamar a este metodo, r->n contendra
    la cantidad de veces que se presenta el dia de la semana 
    correspondiente a la fecha j (j es un int que corresponde 
    al primer lunes, martes, miercoles etc. 
    j\in{1,2,3,4,5,6,7}), en el mes con indice i. Mientras que 
    el apuntador r->intPt apuntara a los numeros de dia en las 
    fechas tales que el dia coincide con el dia de la fecha j 
    del mes con indice i.
    @param i: index del mes; 0 enero, 1 febrero, 2 marzo, etc.
    @param j: primera fecha del mes correspondiente al dia de  
              la semana cuyas fechas que estamos buscando.
    @param r: Conjunto de enteros.
 */
  void fill_SDIT(int i,int j,SetDIntType* r);

  int numdanio;  //numero de anio
};//end class Calendario
#endif
