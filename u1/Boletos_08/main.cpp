#include <iostream>
#include <string>
#include <vector>
#include <ostream>
#include <conio.h>
#include "UPIITA.h"


using namespace std;

void MainMenu();
void CompraMenu();
void AnadirMenu();
void ResumenMenu();
UPIITA Loc;
int MAX;

int main(){
    Loc.GetFile();  
    MainMenu();
    
    Loc.SaveFile();
    return 0;
}//end main()

void CompraMenu(){
     char chr=0,slc;
     int sel;
     MAX=Loc.NumDEventos();
     while(chr!=27){
          fflush(stdin);
          system("cls");
          cout<<" ------------------------------------------"<<endl;
          cout<<"|  CENTRO DE TAQUILLA/ Comprar Boleto      |"<<endl;
          cout<<" ------------------------------------------"<<endl;
          cout<<"\n\n\n"<<endl;
          for(int i=0;i<MAX;i++){
               slc='a'+i;
               cout<<"\t"<<slc<<") "<<Loc.NombEvento[i]<<"\n"<<endl;
          }
          cout<<"\n\n\n"<<endl;
          cout<<"\t\t  ESC) Atras"<<endl;
          chr=getch();
          
          sel=chr-'a';
          if(sel<=('z'-'a') && sel>=0){
               if(sel<MAX){
                    Loc.VentaEvento(sel);
                    chr=27;
               }
               else;
          }
          else;
          
     }
     MainMenu();
}

void AnadirMenu(){
     string NvEvento;
     int disp, vend;
     double folio;
     char chr;
     
     cout<<"\n\n  Esta seguro de crear un nuevo evento?"<<endl;
     cout<<"\n\t  [ENTER] SI    [ ESC ] NO"<<endl;
     chr=getch();
     
     if(chr==13){          
          fflush(stdin);
          system("cls");
          cout<<" ------------------------------------------"<<endl;
          cout<<"|  CENTRO DE TAQUILLA/ Anadir Evento       |"<<endl;
          cout<<" ------------------------------------------"<<endl;
          cout<<"\n\n\n"<<endl;
          cout<<" Nombre del nuevo Evento:   ";
          getline(cin,NvEvento);
          cout<<"\n Inicial Folio:   ";
          cin>>folio;
          cout<<"\n Localidades disponibles:   ";
          cin>>disp;
          cout<<"\n Boletos vendidios en pre-venta:   ";
          cin>>vend;
          Loc.AddEvento(NvEvento,disp,vend,folio);
          Loc.SaveFile();
     }
     else if(chr==27){MainMenu();}
     else{AnadirMenu();}
     MainMenu();
}

void ResumenMenu(){
     char chr=0;
     MAX=Loc.NumDEventos();
     while(chr!=27){
          fflush(stdin);
          system("cls");
          cout<<" ------------------------------------------"<<endl;
          cout<<"|  CENTRO DE TAQUILLA/ Resumen             |"<<endl;
          cout<<" ------------------------------------------"<<endl;
          cout<<"\n\nEventos Registrados: "<<MAX<<"\n"<<endl;
          for(int i=0;i<MAX;i++){
               cout<<"\n ------------------------------------------\n"<<endl;
               cout<<"Evento "<<i+1<<":  "<<Loc.NombEvento[i]<<"."<<endl;
               cout<<"Ultimo Folio: "<<Loc.consecutivos[i]<<endl;
               cout<<"Vendidos: "<<Loc.vendidos[i]<<" de "<<Loc.disponibles[i]<<" localidades."<<endl;
          }
          cout<<"\n\n\t\t  ESC) Atras"<<endl;
          chr=getch();
     }
     MainMenu();
}

void MainMenu(){
     char chr=0,k=169;
     while(chr!=27){
          fflush(stdin);
          system("cls");
          cout<<" ------------------------------------------"<<endl;
          cout<<"|            CENTRO DE TAQUILLA            |"<<endl;
          cout<<" ------------------------------------------"<<endl;
          cout<<"\n\n\n"<<endl;
          cout<<"\t    a) Comprar Boleto\n"<<endl;
          cout<<"\t    b) Anadir Evento\n"<<endl;
          cout<<"\t    c) Resumen/Estadistica\n\n\n\n"<<endl;
          cout<<"\t\t  ESC) Salir"<<endl;
          cout<<"\n\n\n\n\n\n\t\t\t\tby TSR SilverRank."<<k<<endl;
          chr=getch();
          
          if(chr=='a'){CompraMenu(); break;}
          else if(chr=='A'){CompraMenu(); break;}
          else if(chr=='b'){AnadirMenu(); break;}
          else if(chr=='B'){AnadirMenu(); break;}
          else if(chr=='c'){ResumenMenu(); break;}
          else if(chr=='C'){ResumenMenu(); break;}
     } 
}
