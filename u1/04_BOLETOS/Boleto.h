#ifndef _CONTIENE_STATIC_
#define _CONTIENE_STATIC_
#include <iostream>
#include <string>
using namespace std;
 
/**
   @author: 2MV11
   @version: 2015.10.08
   Antes de instanciar esta clase se debe
   inicializar sus variables de clase:empresa,
   consecutivo.
*/
//Declaracion anticipada de clase
//class Boleto;
//string dumm="";
template <typename T>
class Dummy{
public:
	static T dumm;
};
template <typename T>
T Dummy<T>::dumm="";

class Bol{
public:
	string evento;
	vector<Bol*> V;
	virtual void set_numdbol(int);
	virtual int get_numdbol();
	void set_evento(string&);
	Bol():evento(Dummy<string>::dumm){
	}
	Bol(string& e)//:evento(e)
	{
		evento=e;
	}
};//end class Bol

class Boleto : public Bol{
    int numdbol; //num de boleto (por evento)
public:
	static string empresa;
    static int consecutivo; //consecutivo de Boletos          
    //string evento;//Abstraido a class Bol
    //Constructores
    Boleto(){
	}
    Boleto(const string& event){
	  this->set_evento(event); 
      consecutivo++;
      //numdbol=consecutivo;//Esto ya no 2015.10.08
	}
    //Boleto(const string);
    
    friend ostream& operator<<(ostream&, Boleto&);
    int get_numdbol();
//	void set_evento(string);//Ya no 2015.10.08
	void set_numdbol(int);
	void set_evento(const string e){
		evento=e;
	}         
};//end class Boleto
#endif /*_CONTIENE_STATIC_*/
