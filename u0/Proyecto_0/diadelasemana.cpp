#include <stdlib.h>	/* malloc() */
struct fecha{
	int d,m,a;	/* dia, mes, anio */
};
typedef struct fecha Fecha;
char *D[]={(char*)"Lunes",(char*)"Martes"};

char *get_dia(int intNumDia){
	switch(intNumDia){
		case 0:{
			return D[0];
			break;
		}
		case 1:{
			return D[1];
			break;
		}
		default:{
			return (char*)"NO DIA";
			break;
		}
	}
}

Fecha *get_Fecha(int intFecha){
	Fecha *R=(Fecha*)malloc(sizeof(Fecha));
	return R;
}
