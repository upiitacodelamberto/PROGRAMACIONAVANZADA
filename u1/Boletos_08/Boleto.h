#include <iostream>
#include <string>
#include <vector>
#include <ostream>
#include <cstdlib>
#include <time.h>
#include <conio.h>
#include <stdio.h>


using namespace std;

class Boleto{   
  public:
    vector<double> consecutivos;
    vector<int> vendidos;
    vector<int> disponibles;
    vector<string> NombEvento;
    
    void AddEvento(string nombre, int dispo, int vend, double folio){
      NombEvento.push_back(nombre);
      disponibles.push_back(dispo);   
      vendidos.push_back(vend);  
      consecutivos.push_back(folio);  
      
      int even=disponibles.size();
    }
    
    /*PENDIENTE PARA EDICION DE EVENTO EN TIEMPO DE EJECUCION
    void SetEvento(int event, int dispo, int vend, double folio){
      disponibles[event]=dispo;   
      vendidos[event]=vend;  
      consecutivos[event]=folio;  
    }*/
    
    int NumDEventos(){
        int Neventos=disponibles.size();
        return Neventos;
    }
};
