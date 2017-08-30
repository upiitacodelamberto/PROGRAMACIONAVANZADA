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

struct Rac{
	int n;		/* numerador */
	int d;		/* denominador*/
	int mcd;	/* maximo comun divisor*/
	void simplificar();
	void set_mcd();

	Rac& operator+(Rac& RacObj);
	Rac& operator-(Rac& RacObj);
	Rac& operator*(Rac& RacObj);
	Rac& operator/(Rac& RacObj);
	/* constructores */
	Rac(int intNum,int intDen);
	Rac();
friend	ostream& operator<<(ostream& ostreamOut,Rac& RacObj); 
};//end class Rac


