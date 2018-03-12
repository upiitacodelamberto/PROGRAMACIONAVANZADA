/** Pol_Directory.cpp
*/
#include <iostream>
#include <fstream>		/*ifstream,ofstream*/
#include "Pol_Directory.h"
using namespace std;

Pol_Directory::Pol_Directory():size(0),capacity(1){
	the_directory=new Directory_entry[1];
}

Pol_Directory::~Pol_Directory(){
	delete[] the_directory;
}

/** Funci\'on para cargar el archivo de datos.
    pre: El almacenamiento del directorio se ha creado y se encuentra vacio.
         Si existe el archivo consistir\'a de pares nombre_de_variable-coeficientes
		 en l\'ineas adyacentes.
	post: Los datos a partir del archivo se cargan en el directorio.
	@param source_name El nombre del archivo de datos  
*/
void Pol_Directory::load_data(const std::string& source_name){
	// Recordar el nombre del archivo fuente para utilizarlo al salvar.
	this->source_name=source_name;
	// Crear un flujo de entrada que provenga de este archivo
	ifstream in(source_name.c_str());
	if(in){ // si el flujo existe
		string name;
		string coeffs;
		while(getline(in,name)){
			if(getline(in,coeffs)){
				add(name,coeffs);
			}
		}
		in.close();
	}
}

/** Adicionar un nuevo par nombre-coeffs al directorio.
    @param name El nombre de la variable a seragregada
	@param coeffs Los coeficientes de la variable a ser agregada 
*/
void Pol_Directory::add(const std::string& var_name,const std::string& coeffs){
	if(size==capacity){// if no room, reallocate
		reallocate();
	}
	// Agregar una nueva entrada e incrementar size.
	the_directory[size]=Directory_entry(var_name,coeffs);
	size++;
}

/** Crear un nuevo arreglo de las entradas del directorio
    con el doble de capacidad del actual.
*/
void Pol_Directory::reallocate(){
	// Duplicar la capacidad
	capacity*=2;
	// Crear un nuevo arreglo del directorio
	Directory_entry *new_directory=new Directory_entry[capacity];
	// Copiar el antiguo directorio al nuevo
	for(int i=0;i<size;i++){
		new_directory[i]=the_directory[i];
	}
	//Devolver la memoria ocupada por el antiguo directorio
	delete[] the_directory;
	// Poner the_directory a apuntar al nuevo directorio
	the_directory=new_directory;
}

std::string Pol_Directory::lookup_entry(const std::string& var_name) const {
	int index=find(var_name);
	if(index!=-1){
		return the_directory[index].coeffs;
	}else{
		return "";
	}
}

int Pol_Directory::find(const std::string& var_name) const {
	for(int i=0;i<size;i++){
		if(the_directory[i].var_name==var_name){
			return i;
		}
	}
	return -1;
}


