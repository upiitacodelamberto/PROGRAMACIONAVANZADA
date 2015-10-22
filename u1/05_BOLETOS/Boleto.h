#ifndef _BOLETO_
#define _BOLETO_

template <typename T> class Empresa{
public:
  static T str_empresa;
};//end template Empresa

template <typename T>
T Empresa<T>::str_empresa="UPIITA S.A. de C.V.";

class Boleto;
class Bol{
public:
  string empresa;
  string evento;
  void set_evento(string);
  vector<Boleto*> V;

  Bol():empresa(Empresa<string>::str_empresa){ }
  Bol(string evt):empresa(Empresa<string>::str_empresa),evento(evt){ }
};//end class Bol

class Boleto : public Bol{
  static int consecutivo;
public: 
  int numdbol;
  Boleto(){ }
  Boleto(string e);
  void set_evento(string str){ evento=str;}
  static int get_consecutivo(){
    return consecutivo;
  }
};//end class Boleto


#endif /* _BOLETO_ */
