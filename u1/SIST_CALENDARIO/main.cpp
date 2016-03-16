#include <iostream>
#include <vector>
#include <stdlib.h>  /*malloc()*/
using std::cout;
using std::endl;
using std::string;
using std::vector;
#define MAIN_MODULE_PRUEBA
#include "Calendario.h"
#include "Fecha.h"
#include "Dia.h"
#include "Actividad.h"
#include "Alumno.h"
extern string NombresDA[][2];
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
int anio=2016;

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

string MONTH[]={"enero","febrero","marzo","abril","mayo","junio","julio","agosto",
              "septiembre","octubre","noviembre","diciembre"};

SetDIntType* obtener_nums_ddia(string d,string m);
void print_SetDIntYFecha(string d,string m,SetDIntType* SDI);
int index_delmes(string month);
int primera_fecha_delmes(string day,int i);
void fill_SDIT(int i,int j,SetDIntType* r);
void suma_de_horas(vector<Actividad*>);
void alumno_init(vector<Alumno*>& alumno);
void print_alumnos(vector<Alumno*>);

int main(int argc, char** argv) {
  vector<Alumno*> Alum;
  alumno_init(Alum);
  print_alumnos(Alum);
  
  Calendario *Cal2016=new Calendario(2016);
  Fecha f1(4,1); /*4 de febrero*/
  Fecha f2(3,5);/*3 de junio*/

  vector<string> vdd;         /*vector de dias*/
  vdd.push_back("Martes");    /*los dias que hay clase*/
  vdd.push_back("Jueves");
  vector<Fecha*> VDF=Cal2016->get_Fechas(&f1,&f2,vdd); /*vector con las Fechas 
                                                         entre f1 y f2 
                                                         correspondientes a 
                                                         los dias en el vector
                                                         vdd */
  /*construir un vector de apuntadores a Dias no laborables*/
  vector<Dia*> vdnl;
  vdnl.push_back(new Dia(new Fecha(21,2)));      /*Lunes 21 de marzo de 2016*/
  vdnl.push_back(new Dia(new Fecha(22,2)));      /*Martes 22 de marzo de 2016*/
  vdnl.push_back(new Dia(new Fecha(23,2)));      /*Miercoles 23 de marzo de 2016*/
  vdnl.push_back(new Dia(new Fecha(24,2)));      /*Jueves 24 de marzo de 2016*/
  vdnl.push_back(new Dia(new Fecha(24,2)));      /*Viernes 25 de marzo de 2016*/
  vdnl.push_back(new Dia(new Fecha(5,4)));       /*Jueves 5 de mayo de 2016*/
  /*Ahora usando el vector de Fechas VDF y el vector de Dias no laborables vdnl,
    construir un vector de Dias laborables (los dias de clase para los que se 
    planificaran actividades) este vector de Dias laborables se obtendra 
    pasando un mensaje al objeto de clase Calendario*/
  vector<Dia*> VDDC=Cal2016->get_Dias_DC(VDF,vdnl);  /*obtener Vector De Dias de Clase*/
                                                     /*de clase en el salon de clase*/
  /*Se asigna Tiempo Disponible Total segun el dia de que se trate*/
  for(int i=0;i<VDDC.size();i++){
    if(ARREGLO[VDDC[i]->f->m][VDDC[i]->f->d%7]=="Martes")
      VDDC[i]->set_TDT(1.5);
    if(ARREGLO[VDDC[i]->f->m][VDDC[i]->f->d%7]=="Jueves")
      VDDC[i]->set_TDT(1.5);
  }
  /*Se necesita crear las actividades/temas a asignar en los 
    dias de clase disponibles. Se usa usa constructor de Actividad 
    pasando el nombre del Tema y la duracion del Tema/Actividad en horas.*/
  vector<Actividad*> VDA;
  VDA.push_back(new Actividad("Unidad 1 Programacion Orientada a Objetos",0.0));
  VDA.push_back(new Actividad("1.1 Clases",2.0));
  VDA.push_back(new Actividad("1.2 Objetos",1.5));
  VDA.push_back(new Actividad("1.3 Herencia",1.0));
  VDA.push_back(new Actividad("1.4 Polimorfismo",1.0));
  VDA.push_back(new Actividad("1.5 Abstraccion",1.5));
  VDA.push_back(new Actividad("Unidad 2 Entorno de Desarrollo",0.0));
  VDA.push_back(new Actividad("2.1 Ambiente de desarrollo",2.0));
  VDA.push_back(new Actividad("2.2 Proyecto",6.0));
  VDA.push_back(new Actividad("Unidad 3 Interfaz Grafica de Usuario",0.0));
  VDA.push_back(new Actividad("3.1 Controles basicos",4.0));
  VDA.push_back(new Actividad("3.2 Controles Avanzados",5.0));
  VDA.push_back(new Actividad("3.3 Eventos",9.0));
  VDA.push_back(new Actividad("Unidad 4 Puertos y Comunicaciones",0.0));
  VDA.push_back(new Actividad("4.1 Puerto serie",4.0));
  VDA.push_back(new Actividad("4.2 Puerto USB",5.0));
  VDA.push_back(new Actividad("4.3 Comunicacion TCP/IP",2.0));
  VDA.push_back(new Actividad("Unidad 5 Vision",0.0));
  VDA.push_back(new Actividad("5.1 Vision",6.0));

  /*Por ultimo se hace la planeacion pasando el vector de dias de clase y el 
    vector de actividades*/
  //Cal2016->planear(VDDC,VDA);
  Cal2016->planear(VDDC,VDA,Alum);
  /*Finalmente se imprime en pantalla los dias a planear con las actividaes 
    correspondientes por dia de clase entre las fechas f1 y f2.*/
  cout<<"Los dias a planificar son:"<<endl;
  for(int i=0;i<VDDC.size();i++){
    cout<<*VDDC[i]<<endl;
  }
  suma_de_horas(VDA);
  Mauricio_Arturo_Aguilera_Roa *Mauricio=new Mauricio_Arturo_Aguilera_Roa(NombresDA[0][0],NombresDA[0][1]);
  David_Raciel_Arteaga_Martinez *David=new David_Raciel_Arteaga_Martinez(NombresDA[1][0],NombresDA[1][1]);
  Alumno *al=Mauricio;
  al->opye();
  al=David;
  al->opye();
  
#ifdef _WIN32
	system("PAUSE");
#endif
	return 0;
}


//void Calendario::mostrar_fechas(string d,string m){
//  SetDIntType* sdi=obtener_nums_ddia(d,m);
//  print_SetDIntYFecha(d,m,sdi);
//}

void print_SetDIntYFecha(string d,string m,SetDIntType* SDI){
  for(int i=0;i<SDI->n;i++){
    cout<<SDI->intPt[i]<<" de "<<m<<" de 2016"<<endl;
  }
}

/**
 Obtiene los numeros de dia de las fechas de los 
 dias d en el mes m.
 */
SetDIntType* obtener_nums_ddia(string d,string m){
  SetDIntType* r=(SetDIntType*)malloc(sizeof(SetDIntType));
  int i,j;  /* i: index del mes en el arreglo ARREGLO*/
  i=index_delmes(m);
  if(i>=0 && i<12){
    j=primera_fecha_delmes(d,i);
  }
  fill_SDIT(i,j,r);
  return r;
}


/**
 Obtiene el indice correspondiente al mes month. 
 Si month="enero", debe devolver 0, 
 Si month="febrero", debe devolver 1, 
 Si month="marzo", debe devolver 2, 
 etc.
 */
int index_delmes(string month){
  for(int i=0;i<12;i++){
    if(month==MONTH[i])
      return i;
  }
  return -1;/*no se encontro la cadena*/
}

/**
 Devuelve el numero de dia de la primera fecha 
 del mes con indice i (devuelto por 
 index_delmes(string month)), en la que el dia 
 es el string day.
 */
int primera_fecha_delmes(string day,int i){
  if(ARREGLO[i][0]==day) return 7;
  if(ARREGLO[i][1]==day) return 1;
  if(ARREGLO[i][2]==day) return 2;
  if(ARREGLO[i][3]==day) return 3;
  if(ARREGLO[i][4]==day) return 4;
  if(ARREGLO[i][5]==day) return 5;
  if(ARREGLO[i][6]==day) return 6;
  return -1;/*nunca deberia llegarse aqui*/
}

/*Cantidades de dias de los meses del anio (valido para anios bisiestos)*/
int TamDMes[]={
  31,/*enero*/
  29,/*febrero*/
  31,/*marzo*/
  30,/*abril*/
  31,/*mayo*/
  30,/*junio*/
  31,/*julio*/
  31,/*agosto*/
  30,/*septiembre*/
  31,/*octubre*/
  30,/*noviembre*/
  31 /*diciembre*/
};

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
void fill_SDIT(int i,int j,SetDIntType* r){
  int cnt=1,k=j;
  while((k=k+7)<=TamDMes[i])cnt++;
  r->n=cnt;
  k=j;
  r->intPt=(int*)malloc((r->n)*sizeof(int));
  for(int m=0;m<r->n;m++){
    *(r->intPt+m)=k;
    k+=7;
  }
}

void suma_de_horas(vector<Actividad*> vda){
  float sum=0;
  for(int i=0;i<vda.size();i++){
    sum+=vda[i]->TRT;
  }
  cout<<"Total de horas="<<sum<<endl;
}
