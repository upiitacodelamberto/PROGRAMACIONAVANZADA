#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <ostream>
#include <cstdlib>
#include <time.h>
#include <conio.h>
#include <stdio.h>
#include <sstream>
#include <io.h>

#include "Boleto.h"

using namespace std;

//Funciones de Imagen en Pantalla      (Que se vea bonito)

string currentDateTime();
void datoscompra(string&, int&);
void scrcomprobante(string, string, int, double);

//Funciones de Utilidad
void PrintBoleto(string, string, int, double);

class UPIITA: public Boleto{
     struct FormatDoc {
          int evn;
          int vnd[26];
          int dis[26];
          double fol[26];
     }; 
           
     public:                 
     void VentaEvento(int evento){
          int venta;
          string nombre;
          
          datoscompra(nombre, venta);
          
          if(venta+vendidos[evento]<=disponibles[evento]){
               consecutivos[evento]+=venta;
               vendidos[evento]+=venta;
               
               string NEvento=NombEvento[evento];
               double conse=consecutivos[evento];
               scrcomprobante(NEvento,nombre, venta, conse);            
               PrintBoleto(NEvento, nombre, venta, conse);
               
          }
          else{
               cout<<"\n\nLo sentimos, no hay suficientes localidades para esta venta\n\n"<<endl;
               system("pause");
          }
     }
     
     void SaveFile(){
          FormatDoc TSR;
          TSR.evn=disponibles.size();
          
          for(int i=0;i<26;i++){        
               TSR.vnd[i]=0;
               TSR.dis[i]=0;
               TSR.fol[i]=0;
          }
          
          system("attrib -h StrFile.txt /L"); system("cls");
          ofstream OUTTXTFILE("StrFile.txt");
          for(int k=0;k<disponibles.size();k++){
               OUTTXTFILE<<endl<<NombEvento[k];   
               TSR.vnd[k]=vendidos[k];
               TSR.dis[k]=disponibles[k];
               TSR.fol[k]=consecutivos[k];
          }
          OUTTXTFILE.close();
          system("attrib +h StrFile.txt /L");  

          system("attrib -h BinFile.dat /L"); system("cls");
          ofstream OUTFILE("BinFile.dat", ios::out | ios::binary);
          OUTFILE.write(reinterpret_cast<char *>(&TSR), sizeof(FormatDoc));
          OUTFILE.close();
          system("attrib +h BinFile.dat /L"); 
     }
     
     void GetFile(){
          int ACS = access("StrFile.txt",0);
          int ACB = access("BinFile.dat",0);
          if(ACS==0){ if(ACB==0){
               FormatDoc RST;  
               ifstream INFILE("BinFile.dat", ios::in | ios::binary);   
               INFILE.read(reinterpret_cast<char *>(&RST), sizeof(FormatDoc));
               INFILE.close();
   
               int i=-1;
               char txtline[80];
   
               ifstream INTXTFILE;
               INTXTFILE.open("StrFile.txt");
               INTXTFILE.getline(txtline,80,'\n');   
               for(int i=0;i<RST.evn;i++){
                    INTXTFILE.getline(txtline,80,'\n');
                    string str(txtline);
                    NombEvento.push_back(str);
                    disponibles.push_back(RST.dis[i]);   
                    vendidos.push_back(RST.vnd[i]);  
                    consecutivos.push_back(RST.fol[i]);                   
               }
               INTXTFILE.close();
          }else; }else;
     }
};


////////////////////      FUNCIONES DE IMAGEN    ///////////////////////////////
string currentDateTime() {
    time_t     now = time(0);
    struct tm  tstruct;
    char       buf[80];
    tstruct = *localtime(&now);
    strftime(buf, sizeof(buf), "%d/%m/%Y\t%X hrs.", &tstruct);

    return buf;
}
void datoscompra(string& nombre,int& venta){
     fflush(stdin);
     system("cls");
     cout<<"\n"<<endl;
     cout<<"   A nombre de:\n\t";
     getline(cin,nombre);
     cout<<"\n   Cantidad:\n\t";
     cin>>venta;
     cout<<"\n"<<endl;
}
void scrcomprobante(string NE, string n, int v, double f){
     system("cls");
     cout<<"\nVenta concretada con exito.\n\n"<<endl;
     cout<<"   ------------------------------------------"<<endl;
     cout<<"    Evento:  "<<NE<<endl;
     cout<<"   ------------------------------------------"<<endl;
     cout<<"\n     Nombre:\n\t"<<n<<endl;
     cout<<"\n     Cantidad:\n\t"<<v<<endl;
     cout<<"\n     Folio:\n\t"<<f<<endl;
     cout<<"\n     Fecha y Hora:\n\t"<<currentDateTime()<<"\n"<<endl;
     cout<<"   ------------------------------------------"<<endl;
     char k=169;
     cout<<"\t\t\tby TSR SilverRank."<<k<<endl;
     cout<<"\n\n";
}


////////////////////      FUNCIONES DE UTILIDAD    ///////////////////////////////

void PrintBoleto(string NE, string n, int v, double c){
     fflush(stdin);
     const char * NEc = NE.c_str();
     const char * nc = n.c_str();
     string time= currentDateTime();
     const char * timec = time.c_str();
     
     FILE *doc;
     doc = fopen("Comprobante.txt","w");
     
     fprintf(doc,"\n      Venta exitosa               COMPROBANTE               Imprimir\n");
     fprintf(doc,"   ------------------------------------------");
     fprintf(doc,"------------------------------------------\n");
     fprintf(doc,"     Evento:  %s\n",NEc);
     fprintf(doc,"   ------------------------------------------");
     fprintf(doc,"------------------------------------------\n");
     fprintf(doc,"     Nombre:   %s\n",nc);
     fprintf(doc,"     Cantidad:   %d\n",v);
     fprintf(doc,"     Folio:   %.0f\n",c);
     fprintf(doc,"     Fecha y Hora:   %s\n",timec);
     fprintf(doc,"   ------------------------------------------");
     fprintf(doc,"------------------------------------------\n");
     char k=169;
     fprintf(doc,"\t\t\tby TSR SilverRank.%c",k);
 
     fclose(doc);
     
     //system("print comprovante.txt");   Descomentar con una impresora en RED
     system("Comprobante.txt");
}




