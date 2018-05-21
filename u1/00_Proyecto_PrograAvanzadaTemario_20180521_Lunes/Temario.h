/**
 * Temario.h - Define algunas clases para modelar 
 * el programa detallado (Temario) del curso Programaci\'on Avanzada
 * version: 2018.05.18
 */
 
/*Tema 1.1 Clases*/
struct UnidadTematica{
  int NumDUnidad;        /*Subtema 1.2.1 Atributos*/
  int NumDTemas;         /*Debe ser <= 5 y >= 0*/
  char NombreDUnidad[128];
  char Tema[5][128];
  /*Constructor*/
  UnidadTematica();       /* Subtema 1.2.2 M\'etodos */
  UnidadTematica(int){}
  std::string string_show();
  virtual std::string get_nombre();
};/*end class UnidadTematica*/

/*Tema 1.3 Herencia: La clase SubTema es derivada de 
  la clase UnidadTematica*/
struct SubTema : public UnidadTematica{
  int NumDTema;
  int NumDSubTema; 
  char NombreDSubTema[128];
  SubTema(int num_tema,int num_subtema);
  std::string string_show();
  std::string get_nombre();       
};/*end class SubTema*/





