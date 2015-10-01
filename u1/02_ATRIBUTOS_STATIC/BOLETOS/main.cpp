#include <cstdlib>
#include <iostream>
#include <string>
#include "Boleto.h"
 
using namespace std;
 
Boleto::Boleto(const string& e){
    evento=e;
}

const string upiita="UPIITA S.A.DE C.V.";
string evento1="Guerra de Robots";

/* La variable de clase (static) se debe inicializar 
   en alcance de archivo. */
string Boleto::empresa=upiita;
int Boleto::consecutivo=0;
                       
int main(int argc, char *argv[])
{
    //Boleto::empresa=upiita; //Esto se DEBE hacer en alcance de archivo!!
                              //(vease la sentencias previas a main())

    /* para llevar la cuenta de boletos emitidos */
    //Boleto::consecutivo=0;  //Esto tambien se DEBE hacerse en alcance de archivo!!

    Boleto A(evento1);
    Boleto B(evento1);
    cout << A.consecutivo << " "
         << B.consecutivo << "\n";

#ifdef _WIN32
    system("PAUSE");
#endif
    return EXIT_SUCCESS;
}//end main()
