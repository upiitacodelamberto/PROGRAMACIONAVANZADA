#include <iostream>
#include <vector>
using namespace std;
#include <stdio.h>
#include "Pol_Directory.h"
#include "String_Tokenizer.h"

#define COMANDO_0
#ifdef COMANDO_0
//Prototipos de funciones
void proccess_operation(Pol_Directory&,char *,char *,char *);
void do_suma(Pol_Directory&,char *,char *);

int main(int argc,char *argv[]){
//	cout<<"Dummy HOLA MUNDO desde "<<argv[0]<<"!!!"<<endl;
	cout<<"Dummy HOLA MUNDO!!!"<<endl;
	if(argc<2){
		cout<<"Faltan argumentos!"<<endl;
		return 1;
	}else{
		for(int i=0;i<argc;i++){
			cout<<"argv["<<i<<"]: "<<argv[i]<<endl;
		}
		Pol_Directory the_directory;
		the_directory.load_data(argv[1]);
		proccess_operation(the_directory,argv[2],argv[3],argv[4]);
	}
	return 0;
}
#endif /*COMANDO_0*/


void proccess_operation(Pol_Directory& the_directory,char *op1,char *operador,char *op2){
	switch(*operador){
		case '+':{
			do_suma(the_directory,op1,op2);
			break;
		}
	}
}

void do_suma(Pol_Directory& the_directory,char *op1,char *op2){
	string operando1(op1);
	string operando2(op2);
	string coeffs1=the_directory.lookup_entry(operando1);
	string coeffs2=the_directory.lookup_entry(operando2);
	String_Tokenizer tokenizer1(coeffs1, ":");
	String_Tokenizer tokenizer2(coeffs2, ":");
	int tokcount=0;
	vector<string> arr1;
	vector<string> arr2;
	while(tokenizer1.has_more_tokens()){
        arr1[tokcount]=tokenizer1.next_token();
        tokcount++;
    }//end while()
    tokcount=0;
	while(tokenizer2.has_more_tokens()){
        arr1[tokcount]=tokenizer2.next_token();
        tokcount++;
    }//end while()
    for(int i=0;i<arr1.size();i++){
    	cout<<arr1[i]<<" ";
	}
	cout<<endl;
	for(int i=0;i<arr2.size();i++){
    	cout<<arr2[i]<<" ";
	}
	cout<<endl;
}
