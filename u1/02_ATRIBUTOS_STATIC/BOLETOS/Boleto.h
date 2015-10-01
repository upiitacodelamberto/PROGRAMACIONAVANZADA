#ifndef _CONTIENE_STATIC_
#define _CONTIENE_STATIC_
#include <iostream>
using namespace std;
 
/**
   @author: 2MV11
   @version: 2015.09.30
   Antes de instanciar esta clase se debe
   inicializar sus variables de clase:empresa,
   consecutivo.
*/
class Boleto{
      public:
             static int consecutivo;
             static string empresa;
              
             string evento;
             Boleto(const string&);
};//end class Boleto
#endif /*_CONTIENE_STATIC_*/
