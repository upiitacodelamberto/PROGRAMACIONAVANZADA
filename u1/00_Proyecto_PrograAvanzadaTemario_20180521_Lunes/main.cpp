#include <cstdlib>
#include <iostream>
#include <vector>
#include <stdio.h>
#include "Temario.h"
#include "UT_Directory.h"
#include "String_Tokenizer.h"
//#define EJEMPLIFICAR_POLIMORFISMO
using namespace std;
void do_save(UT_Directory&);

int main(int argc, char *argv[])
{ /*Tema 1.2 Objetos*/
  int respuesta=0;
  char new_unidad[128];
  string nueva_unidad;
  string resultado;
  Directory_entry DE;
  UT_Directory the_directory;
  string source_name("unidadestematicas.txt");
  the_directory.load_data(source_name);
  String_Tokenizer tokenizer0;
  vector<string> arr0;
  //UnidadTematica UT(1);
  int NdUnidad,NdTema,NdSubtema; /*Num de Unidad,Tema,Subtema*/
  string string_tmp;
  cout<<"Indique la operaci\\'on a realizar\n \
  (0 - Mostrar Unidades capturadas/1 - Capturar Unidad Tem\'atica):";
  scanf("%d%*c",&respuesta);
  if(respuesta==0){
    cout<<"\nUnidades Tem\\'aticas:"<<endl;
    for(int i=0;i<the_directory.get_size();i++){
      DE=the_directory.get_entry(i);
      cout<<DE.var_name<<endl;
      tokenizer0=String_Tokenizer(DE.var_name,":");
      if(tokenizer0.has_more_tokens()){
        string_tmp=tokenizer0.next_token();
        if(string_tmp.size()>=7){
          string_tmp=string_tmp.substr(7);  /*string_tmp primero contiene Unidad <#>*/
        }else{
          string_tmp="";
        }
      }else{
        string_tmp="";
      }
      tokenizer0=String_Tokenizer(DE.coeffs,":");
      while(tokenizer0.has_more_tokens()){
        arr0.push_back(tokenizer0.next_token());
      }
      for(int j=0;j<arr0.size();j++){
        cout<<string_tmp<<"."<<j+1<<" "<<arr0[j]<<endl;
      }
      arr0.clear();
    }/*end for()*/
  }else if(respuesta==1){
    UnidadTematica UT;
    //UT=UnidadTematica();/*Ejecutar constructor*/ /*Se instancia un Objeto*/
    printf("Unidad %d %s\n",UT.NumDUnidad,UT.NombreDUnidad);
    printf("%-7s%-64s\n","Num","Tema");
    for(int i=0;i<UT.NumDTemas;i++){
      printf("%-7d%-64s\n",i+1,UT.Tema[i]);
    }
  
    NdUnidad=UT.NumDUnidad;
    sprintf(new_unidad,"Unidad %d: %s",UT.NumDUnidad,UT.NombreDUnidad);
    nueva_unidad=string(new_unidad);
    resultado=UT.string_show();
    the_directory.add_or_change_entry(nueva_unidad,resultado);
    printf("Esta unidad tiene subtemas? (1 - SI / 0 - NO)\n");
    scanf("%d%*c",&respuesta);
    if(respuesta){
      do{
        printf("Numero de tema? ");
        scanf("%d%*c",&NdTema);
        printf("Numero de subtema? ");
        scanf("%d%*c",&NdSubtema);
        SubTema ST(NdTema,NdSubtema);
        sprintf(new_unidad,"%d.%d.%d: %s",
                NdUnidad,NdTema,NdSubtema,ST.NombreDSubTema);
        resultado=ST.string_show();
        nueva_unidad=string(new_unidad);
        the_directory.add_or_change_entry(nueva_unidad,resultado);
        printf("Desea agregar otro subtema de esta unidad? (1 - SI / 0 - NO)\n");
        scanf("%d%*c",&respuesta);
      }while(respuesta);
    }
    printf("Desea guardar los datos de esta unidad? (1 - SI / 0 - NO)\n");
    scanf("%d%*c",&respuesta);
    if(respuesta){
      do_save(the_directory);
    }
    cout<<UT.get_nombre()<<endl;
  }/*end else if()*/
  //UnidadTematica UT1;
#ifdef EJEMPLIFICAR_POLIMORFISMO
  UnidadTematica *UT_Pt= new UnidadTematica();
  cout<<"Nombre de Unidad:"<<UT_Pt->get_nombre()<<endl;
  SubTema *ST=new SubTema(2,1);
  UT_Pt=ST;
  cout<<"Nombre de subtema:"<<UT_Pt->get_nombre()<<endl;
#endif /* EJEMPLIFICAR_POLIMORFISMO */
  
  system("PAUSE");
  return EXIT_SUCCESS;
}



void do_save(UT_Directory& the_directory){
	the_directory.save();
}



