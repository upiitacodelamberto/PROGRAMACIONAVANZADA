#include <vector>
#include "Boleto.h"
using std::vector;


//Boleto::Boleto(const string e){
//	consecutivo++;//numdbol=consecutivo;//Esto ya no 2015.10.08 
//    //evento=e;//Los Boletos ya no tienen evento 2015.10.08
//}

void Boleto::set_numdbol(int N){
	numdbol=N;
}

int Boleto::get_numdbol(){
	return numdbol;
}
