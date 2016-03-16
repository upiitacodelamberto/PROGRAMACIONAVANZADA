#ifndef FECHA_H
#define FECHA_H

typedef struct Fecha{
  int d;/*dia*/
  int m;/*mes, 0 enero, 1 febrero, 2 marzo, etc.*/
  Fecha():d(0),m(0){ }
  Fecha(int a,int b):d(a),m(b){ }
  /*sobrescritura del operador ==*/
  bool operator==(Fecha& f){
    return ((d==f.d)&&(m==f.m));
  }
} Fecha;
#endif /*FECHA_H*/
