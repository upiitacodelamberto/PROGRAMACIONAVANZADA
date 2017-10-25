struct NumDListYProm{
	int intDato;	/*Num. de lista del participante*/
	float floatProm;/*Promedio de las evaluaciones del participante*/
};

class A{
//	int intDato;
	NumDListYProm NdLyProm; 
	public:
	int get_intDato(){
//		return intDato;
		return NdLyProm.intDato;
	}
	void set_intDato(int dato){
//		intDato=dato;
		NdLyProm.intDato=dato;
	}
//	int get_intDato();
//	void set_intDato(int dato);
};//end class A
