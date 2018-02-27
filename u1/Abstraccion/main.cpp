#include <iostream>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */


#include "B.h"


int main(int argc, char** argv) {
//	A Aobj;
//	Aobj.set_intDato(10);
////	cout<<Aobj.intDato<<endl;
//	cout<<Aobj.get_intDato()<<endl;
	B *Bobj=new B();
	Bobj->set_intDato(20);
	cout<<Bobj->get_intDato()<<endl;
	delete Bobj;
	return 0;
}//end main()
