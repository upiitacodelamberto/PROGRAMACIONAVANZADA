// TestPdfLatex.cpp

#include <iostream>
#include <fstream>

#include <windows.h>
using namespace std;

//#define TEST_PDFLATEX
#ifdef TEST_PDFLATEX
int
main(void)
{
	string dest_file="Asignaciones.tex";
	ofstream out(dest_file.c_str());
	STARTUPINFO si;
	PROCESS_INFORMATION pi;
	if(out){
		out<<"\\documentclass{article}"<<endl;
		out<<"\\begin{document}"<<endl;
		out<<"\\begin{center}"<<endl;
		out<<"\\begin{tabular}{|p{2.0in}|p{2.0in}|}"<<endl;
		out<<"\\hline"<<endl;
		out<<"{\\bf Asignaci\ \'on} & {\\bf Fecha l\\'imite}\
		\\\\ \\hline"<<endl;
		out<<"Interprete de \\'ordenes para hacer operaciones\
		     con polinomios &"<<endl; 
		out<<"27 de octubre de 2017\\\\ \\hline"<<endl;
		out<<"\\end{tabular}"<<endl;
		out<<"\\end{center}"<<endl;
		out<<"\\end{document}"<<endl;
		out.close();
		ZeroMemory(&si,sizeof(si));
		si.cb=sizeof(si);
		ZeroMemory(&pi,sizeof(pi));
		if(!CreateProcess("C:/Program Files (x86)/MiKTeX 2.9\
/miktex/bin/pdflatex.exe",\
"pdflatex.exe ./Asignaciones.tex",0,0,0,0,0,0,&si,&pi)){
			cout<<"Hubo un problema al llamar a pdflatex.exe\n";
		}
		WaitForSingleObject(pi.hProcess,INFINITE);
	}else{
		cout<<"No fue posible crear el flujo de salida!!!"<<endl;
		return 1;
	}
	return 0;
}
#endif /* TEST_PDFLATEX */
