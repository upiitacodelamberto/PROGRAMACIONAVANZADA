#include "A.h"
#include "B.h"
	int B::get_intDato(){
		APointer->get_intDato();
	}
	void B::set_intDato(int dato){
		APointer->set_intDato(dato);
	}
	//Constructor
	B::B(){
		APointer=new A();
	}
