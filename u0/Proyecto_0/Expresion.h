/**expresion.h
 */
/* declaraciones anticipadas */
struct Box;
struct Rac;

/** Clase sin secciones privadas */
struct Expresion{
	Box *BoxOp1,*BoxOp2,*BoxResult;
	Box *BoxOperador;
	static Box *BoxIgual;
	long longMaxAlturaDBox;		/* atributo calculado */
	static COORD COORD_C;/* posicion del cursor */
	Expresion(Box *Op1,Box *Operador,Box *Op2,Box *Result);	/* constructor */
	Expresion();
	virtual void print();
};//end class Expresion

/* clase abstracta */
struct Box{
	int intLongDBase;		/* atributo calculado */
	int intLongDAltura;		/* atributo calculado */

	//friend ostream& operator<<(ostream& out,Box *B);
	virtual void set_coord(COORD c)=0;	/* funcion virtual pura*/
	virtual Rac *get_Rac()=0;
	virtual int get_intLongDBase()=0;
	virtual char get_op()=0;
	virtual void print(COORD)=0;
};//end class Box

struct BoxStringEqual : public Box{
	static std::string equal;
	COORD coord;
	BoxStringEqual();
	void set_coord(COORD c);
	Rac *get_Rac();
	int get_intLongDBase();
	char get_op();
	void print(COORD);
};//end class BoxStringEqual

struct BoxRac : public Box{
	Rac *R;
	COORD coord;
	BoxRac(Rac *r);
	void set_coord(COORD c);
	Rac *get_Rac();
	int get_intLongDBase();
	char get_op();
	void print(COORD);
};//end class BoxRac

struct BoxStringOperator : public Box{
	char op;
	COORD coord;
	BoxStringOperator(char);
	void set_coord(COORD c);
	Rac *get_Rac();
	int get_intLongDBase();
	char get_op();
	void print(COORD);
};//end class BoxStringOperator

struct ExpresionASimplificar : public Expresion{
	Rac *RacOrig;
	Rac *RacSimpl;
	//ExpresionASimplificar(Rac *RacObj);
	ExpresionASimplificar(Box *Op1,Box *Op2);
	ExpresionASimplificar(Box *Op1);
	void print();
};//enc class ExpresionASimplificar
