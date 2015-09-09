#ifndef _FECHA_
#define _FECHA_
class Fecha{
      int dia;
      int mes;
      int anio;
public: Fecha(int, int, int);
        char *nombre_del_dia();/* "Lunes", "Martes", etc. */
};
#endif 
