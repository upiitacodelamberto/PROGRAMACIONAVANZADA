/*Alumno.h*/
#ifndef ALUMNO_H
#define ALUMNO_H

#define CLASSAL(fn,ln)  class fn##_##ln : public Alumno{\
public:\
  fn##_##ln (string firstn,string lastn):Alumno(firstn,lastn){ }\
  void opye(void);\
}

class Alumno{
public:
static int NDL;     /*variable de clase*/
  int ndl;          /*numero de lista, variable de objeto*/
  string firstname;
  string lastname;
  Alumno(string firstn,string lastn):firstname(firstn),lastname(lastn){
    NDL++;ndl=NDL;
  }
  virtual void opye(void){ }
friend ostream& operator<<(ostream& out,Alumno& a);
};//end class Alumno

CLASSAL(Mauricio_Arturo,Aguilera_Roa);
CLASSAL(David_Raciel,Arteaga_Martinez);
CLASSAL(Paulino_Enrique,Cabrero_Palomino);
CLASSAL(Manuel_Caleb,Flores_Hernandez);
CLASSAL(Juan_Diego,Gonzalez_Gonzalez);
CLASSAL(Adad_Yanzen,Hernandez_Archundia);
CLASSAL(Hector_Gerardo,Hernendez_Marcelo);
CLASSAL(Julio_Ivan,Martinez_Garcia);
CLASSAL(Eduardo_Michell,Munioz_Hernandez);
CLASSAL(Juan_Manuel,Rodriguez_Sanchez);
CLASSAL(Edson_Daniel,Soto_Avendanio);
CLASSAL(Admin,Zuniiga_Martinez);
#endif /*ALUMNO_H*/
