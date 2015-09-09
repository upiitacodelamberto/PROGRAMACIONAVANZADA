#include <cstdlib>
#include <iostream>
#include "Fecha20150909.h"

using namespace std;

int main(int argc, char *argv[])
{
    //Indstanciar un objeto de la clase Fecha
    Fecha F(9,9,2015);
    cout << F.nombre_del_dia() << "\n";
    system("PAUSE");
    return EXIT_SUCCESS;
}
