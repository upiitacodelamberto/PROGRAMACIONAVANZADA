/**Expresion.cpp
*/
#include <windows.h>	/* COORD,SetConsoleCursorPosition(),GetConsoleScreenBufferInfo() */
#include <iostream>		/* ostream */
#include <windows.h>
#include <stdio.h>
using namespace std;	/* cout, ostream */
#include "Expresion.h"
#include "myfecha.h"

#define max(a,b)	(a>b)?a:b

//Defines gotoxy() for ANSI C compilers.
void gotoxy(short x, short y) {
	COORD pos = {x, y};
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

COORD GetConsoleCursorPosition(HANDLE hConsoleOutput)
{
    CONSOLE_SCREEN_BUFFER_INFO cbsi;
    if (GetConsoleScreenBufferInfo(hConsoleOutput, &cbsi))
    {
        return cbsi.dwCursorPosition;
    }
    else
    {
        // The function failed. Call GetLastError() for details.
        COORD invalid = { 0, 0 };
        return invalid;
    }
}

/* Inicializaciones en alcance de archivo */
COORD Expresion::COORD_C={0,0};
std::string BoxStringEqual::equal="=";
Box *Expresion::BoxIgual=new BoxStringEqual();
//Box *ExpresionASimplificar::BoxIgual=new BoxStringEqual();

/* Constructor */
Expresion::Expresion(Box *Op1,Box *Operador,Box *Op2,Box *Result)
:BoxOp1(Op1),BoxOperador(Operador),BoxOp2(Op2),BoxResult(Result){
	long maxH=BoxOp1->intLongDAltura;
	if(BoxOperador->intLongDAltura>maxH){
		maxH=BoxOperador->intLongDAltura;
	}
	if(BoxOp2->intLongDAltura>maxH){
		maxH=BoxOp2->intLongDAltura;
	}
	if(BoxResult->intLongDAltura>maxH){
		maxH=BoxResult->intLongDAltura;
	}
	longMaxAlturaDBox=maxH;
}

void Expresion::print(){
	COORD pos,pos_inic=GetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE));
	short shortY=pos_inic.Y;
	short shortX=pos_inic.X;
	
	BoxOp1->set_coord(pos_inic);
	
	/*Primer operando*/
	pos={(short)pos_inic.X+1,(short)pos_inic.Y};
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),pos);
	cout<<BoxOp1->get_Rac()->n;
	pos={shortX,shortY+1};
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),pos);
	for(int i=0;i<BoxOp1->get_intLongDBase();i++){
		cout<<'-';
	}
	pos={shortX+1,shortY+2};
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),pos);
	cout<<BoxOp1->get_Rac()->d;
	
	/*operador*/
	pos={shortX+BoxOp1->get_intLongDBase()+1,shortY+1};
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),pos);
	cout<<BoxOperador->get_op();

	/*segundo operando*/
	pos={shortX+BoxOp1->get_intLongDBase()+BoxOperador->get_intLongDBase()+3,shortY};
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),pos);
	cout<<BoxOp2->get_Rac()->n;
	pos={shortX+BoxOp1->get_intLongDBase()+BoxOperador->get_intLongDBase()+2,shortY+1};
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),pos);
	for(int i=0;i<BoxOp1->get_intLongDBase();i++){
		cout<<'-';
	}
	pos={shortX+BoxOp1->get_intLongDBase()+BoxOperador->get_intLongDBase()+3,shortY+2};
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),pos);
	cout<<BoxOp2->get_Rac()->d;
	
	/*igual*/
	pos={shortX+BoxOp1->get_intLongDBase()+BoxOperador->get_intLongDBase()+
			BoxOp2->get_intLongDBase()+3,shortY+1};
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),pos);
	cout<<Expresion::BoxIgual->get_op();
	
	/*resultado*/
	pos={shortX+BoxOp1->get_intLongDBase()+BoxOperador->get_intLongDBase()+
			BoxOp2->get_intLongDBase()+BoxIgual->get_intLongDBase()+5,shortY};
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),pos);
	cout<<BoxResult->get_Rac()->n;
	pos={shortX+BoxOp1->get_intLongDBase()+BoxOperador->get_intLongDBase()+
			BoxOp2->get_intLongDBase()+BoxIgual->get_intLongDBase()+4,shortY+1};
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),pos);
	for(int i=0;i<BoxResult->get_intLongDBase();i++){
		cout<<'-';
	}
	pos={shortX+BoxOp1->get_intLongDBase()+BoxOperador->get_intLongDBase()+
			BoxOp2->get_intLongDBase()+BoxIgual->get_intLongDBase()+5,shortY+2};
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),pos);
	cout<<BoxResult->get_Rac()->d;		
	
	pos={shortX,shortY+longMaxAlturaDBox};
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),pos);
}//end Expresion::print()

BoxStringEqual::BoxStringEqual(){
	intLongDBase=intLongDAltura=1;
}

BoxStringOperator::BoxStringOperator(char c):op(c){
	intLongDBase=intLongDAltura=1;
}

BoxRac::BoxRac(Rac *r):R(r){
	int count_n=1,count_d=1,divisor=10;
	intLongDAltura=3;
//	cout<<"BoxRac: n="<<R->n<<" "<<R->d<<endl;
	while(((R->n)/divisor)!=0){
		count_n++;
		divisor*=10;
	}
	divisor=10;
	while(((R->d)/divisor)!=0){
		count_d++;
		divisor*=10;
	}
	intLongDBase=max(count_n,count_d);
	intLongDBase+=2;
}

void BoxRac::set_coord(COORD c){
	coord=c;
}
Rac *BoxRac::get_Rac(){
	return R;
}
int BoxRac::get_intLongDBase(){
	return intLongDBase;
}
char BoxRac::get_op(){//
	return 'Z';
}

void BoxStringEqual::set_coord(COORD c){
	coord=c;
}
Rac *BoxStringEqual::get_Rac(){//Stub
	return new Rac();
}
int BoxStringEqual::get_intLongDBase(){
	return intLongDBase;
}
char BoxStringEqual::get_op(){//Stub
	return BoxStringEqual::equal[0];
}
void BoxStringEqual::print(COORD pos_inic){
//	COORD pos={(short)pos_inic.X,(short)pos_inic.Y};
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),pos_inic);
	cout<<get_op();
}

void BoxStringOperator::set_coord(COORD c){
	coord=c;
}
Rac *BoxStringOperator::get_Rac(){//Stub
	return new Rac();
}
int BoxStringOperator::get_intLongDBase(){
	return intLongDBase;
}
char BoxStringOperator::get_op(){
	return op;
}
void BoxStringOperator::print(COORD pos_inic){
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),pos_inic);
	cout<<get_op();
}

//ExpresionASimplificar::ExpresionASimplificar(Rac *RacObj):RacOrig(RacObj){
ExpresionASimplificar::ExpresionASimplificar(Box *Op1,Box *Op2){
	BoxOp1=Op1;
	BoxOp2=Op2;
	long maxH=BoxOp1->intLongDAltura;
	if(BoxOp2->intLongDAltura>maxH){
		maxH=BoxOp2->intLongDAltura;
	}
	longMaxAlturaDBox=maxH;
}
ExpresionASimplificar::ExpresionASimplificar(Box *Op1){
	BoxOp1=Op1;
	BoxOp2=new BoxRac(new Rac(Op1->get_Rac()->n/Op1->get_Rac()->mcd,
							Op1->get_Rac()->d/Op1->get_Rac()->mcd));
	long maxH=BoxOp1->intLongDAltura;
	if(BoxOp2->intLongDAltura>maxH){
		maxH=BoxOp2->intLongDAltura;
	}
	longMaxAlturaDBox=maxH;
}
Expresion::Expresion(){
}

void ExpresionASimplificar::print(){
	COORD pos,pos_inic=GetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE));
	BoxOp1->set_coord(pos_inic);
	BoxOp1->print(pos_inic);
	pos={pos_inic.X+BoxOp1->get_intLongDBase()+1,pos_inic.Y+1};
//	this->BoxIgual->print(pos);
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),pos);
	cout<<"=";
	pos={pos_inic.X+BoxOp1->get_intLongDBase()+BoxIgual->get_intLongDBase()+2,pos_inic.Y};
	BoxOp2->print(pos);
}

void BoxRac::print(COORD pos_inic){
	COORD pos={pos_inic.X+1,pos_inic.Y};
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),pos);
	cout<<get_Rac()->n;
	pos={pos_inic.X,pos_inic.Y+1};
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),pos);
	for(int i=0;i<get_intLongDBase();i++){
		cout<<'-';
	}
	pos={pos_inic.X+1,pos_inic.Y+2};
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),pos);
	cout<<get_Rac()->d;
}
