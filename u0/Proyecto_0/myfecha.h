/** myfecha.h
 * Introduccion a las clases
 * En C++ las estructuras son clases sin secciones privadas.
 */
struct fecha{
	int d,m,a;	/* dia, mes, anio */
	void to_string_Pt();
	void set_dia();
	string dia;
};
typedef struct fecha Fecha;
