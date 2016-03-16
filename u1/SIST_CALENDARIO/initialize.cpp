/*initialize.cpp*/
#include <iostream>
#include <vector>
#include <ostream>
using std::cout;
using std::endl;
using std::string;
using std::vector;
using std::ostream;
#include "Alumno.h"
extern int NUMDALUMNOS; /*cantidad de filas del siguiente arreglo bidimensional*/
extern string NombresDA[][2];

void alumno_init(vector<Alumno*>& alumno){
  for(int i=0;i<NUMDALUMNOS;i++){
    alumno.push_back(new Alumno(NombresDA[i][0],NombresDA[i][1]));	
  }
}

void print_alumnos(vector<Alumno*> vda){
  for(int i=0;i<vda.size();i++) cout<<*vda[i]<<endl;
}
