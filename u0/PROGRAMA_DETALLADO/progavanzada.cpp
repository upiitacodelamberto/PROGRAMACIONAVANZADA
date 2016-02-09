#include "DefaultNames.h"
#define NULL ((void *)0)
#include <wchar.h> /* wchar_t */


//<!--INFORMACION UNIDAD 1
/* Unidad 1 */
char Unidad_1[] = "Programacion Orientada a \
Objetos";

/* Temas Unidad 1 */
char Tema_1_1[] = "Clases";
char Tema_1_2[] = "Objetos";
char Tema_1_3[]="Herencia";
char Tema_1_4[]="Polimorfismo";
char Tema_1_5[]="Abstraccion";
char *nombresdtemasdu1[] = { Tema_1_1, Tema_1_2, Tema_1_3, Tema_1_4, Tema_1_5 };

/* Subtemas Unidad 1 */
char *nombresdsubtemasdu1t1[]={NULL};
char *nombresdsubtemasdu1t2[]={"Atributos","Metodos"};
char *nombresdsubtemasdu1t3[]={NULL};
char *nombresdsubtemasdu1t4[]={NULL};
char *nombresdsubtemasdu1t5[]={NULL};
char **nombresdsubtemasdu1[] = { nombresdsubtemasdu1t1, nombresdsubtemasdu1t2, 
nombresdsubtemasdu1t3, nombresdsubtemasdu1t4, nombresdsubtemasdu1t5};

/*cantidades de subtemas de los temas de u1*/
//int numdsubtemasdu1[] = {0, 2, 0, 0, 0};
int numdsubtemasdu1[] = {0, 0, 0, 0, 0};
//-->


//<!--INFORMACION UNIDAD 2
/* Unidad 2 */
char Unidad_2[]="Entorno de Desarrollo";

/* Temas Unidad 2 */
char Tema_2_1[]="Ambiente de Desarrollo";
char Tema_2_2[]="Proyecto";
char *nombresdtemasdu2[]={Tema_2_1, Tema_2_2};

/* Subtemas Unidad 2 */
char *nombresdsubtemasdu2t1[]={"Barra de menus","Area de trabajo"};
char *nombresdsubtemasdu2t2[]={"Crear un proyecto","Configurar bibliotecas",\
"Cargar un proyecto","Compilar un proyecto"};
char **nombresdsubtemasdu2[]={nombresdsubtemasdu2t1, nombresdsubtemasdu2t2};

/*cantidades de subtemas de los temas de u2*/
//int numdsubtemasdu2[]={2, 4};
int numdsubtemasdu2[]={0, 0};
//-->


//<!--INFORMACION UNIDAD 3
/* Unidad 3 */
char Unidad_3[]="Interfaz grafica de usuario (GUI)";

/* Temas Unidad 3 */
char Tema_3_1[]={"Controles Basicos"};
char Tema_3_2[]={"Controles Avanzados"};
char Tema_3_3[]={"Eventos"};
char *nombresdtemasdu3[]={Tema_3_1, Tema_3_2, Tema_3_3};

/* Subtemas Unidad 3 */
char *nombresdsubtemasdu3t1[]={"Formas","Botones","Etiquetas"};
char *nombresdsubtemasdu3t2[]={"Control ListBox","Control ComboBox",\
"Cuadros de dialogo de archivo","Cuadros de dialogo de imagenes"};
char *nombresdsubtemasdu3t3[]={"Evento Clic","Evento OnChange",\
"Evento OnEnter","Evento OnExit","Evento OnTimer","Evento OnMouseDown, OnMouseUp",\
"Evento OnKeyPress, OnKeyUp, Evento OnKeyDown"};
char **nombresdsubtemasdu3[]={
   nombresdsubtemasdu3t1,nombresdsubtemasdu3t2,nombresdsubtemasdu3t3};

/*cantidades de subtemas de los temas de u3*/
//int numdsubtemasdu3[] = {3, 4, 8};
int numdsubtemasdu3[] = {0, 0, 0};
//-->


//<!--INFORMACION UNIDAD 4
/* Unidad 4 */
char Unidad_4[]="Puertos y comunicaciones";

/* Temas Unidad 4 */
char Tema_4_1[]="Puerto serie";
char Tema_4_2[]="Puerto USB";
char Tema_4_3[]="Comunicacion TCP/IP";
char *nombresdtemasdu4[]={Tema_4_1, Tema_4_2, Tema_4_3};

/* Subtemas Unidad 4 */
char *nombresdsubtemasdu4t1[]={"Principio de funcionamiento","Abrir comunicacion",\
"Configuracion de velocidad, tamanio de datos, paridad, bit de paro",\
"Tranferir datos","Recibir datos"};
char *nombresdsubtemasdu4t2[]={"Caracteristicas del puerto USB","Teoria de operacion",\
"Controladores y bibliotecas dinamicas","HID USB","Implmentacion en Hardware",\
"Implementacion en software"};
char *nombresdsubtemasdu4t3[]={"Crear socket","Asociar un socket","Escuchar",\
"Conectar","Aceptar conexion","Enviar","Cerrar"};
char **nombresdsubtemasdu4[]={
   nombresdsubtemasdu4t1, nombresdsubtemasdu4t2, nombresdsubtemasdu4t3};

/*cantidades de subtemas de los temas de u4*/
//int numdsubtemasdu4[] = {5, 6, 7};
int numdsubtemasdu4[] = {0, 0, 0};
//-->


//<!--INFORMACION UNIDAD 5
/* Unidad 5 */
char Unidad_5[]="Vision";

/* Temas Unidad 5 */
char Tema_5_1[]="Vision";
char *nombresdtemasdu5[]={Tema_5_1};

/* Subtemas Unidad 5 */
char *nombresdsubtemasdu5t1[]={"Crear ventana de captura","Conectar el controlador",\
"Vista previa","Capturar una imagen","Manipular pixeles"};
char **nombresdsubtemasdu5[]={nombresdsubtemasdu5t1};

/*cantidades de subtemas de los temas de u5*/
//int numdsubtemasdu5[] = {5};
int numdsubtemasdu5[] = {0};
//-->


//<!--INFORMACION GLOBAL DE LA UA PROGRAMACION AVANZADA
/* Nombre de la Unidad de Aprendizaje (UA) */
char unidaddaprendizaje[]="PROGRAMACION AVANZADA"; 
int numdunidades = 5; /* numero de unidades de la UA */

//wchar_t *unit[] = {Unidad_1, Unidad_2, Unidad_3, Unidad_4, Unidad_5};
char *unit[] = {Unidad_1, Unidad_2, Unidad_3, Unidad_4, Unidad_5};
int numdtemas[] = {5, 2, 3, 3, 1};/* cantidades de temas de las unidades */

char ***nombresdsubtemas[]={nombresdsubtemasdu1, nombresdsubtemasdu2, 
    nombresdsubtemasdu3, nombresdsubtemasdu4, nombresdsubtemasdu5};

int *numdsubtemas[] = {numdsubtemasdu1, numdsubtemasdu2, 
    numdsubtemasdu3, numdsubtemasdu4, numdsubtemasdu5};
//-->
