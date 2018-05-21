/** Directory_entry.h
*/
#ifndef DIRECTORY_ENTRY
#define DIRECTORY_ENTRY
#include <string>
/*Proyecto ProgDetallado*/
class Directory_entry {
public:
	std::string var_name;
	std::string coeffs;    /*En este proyecto la cadena coeffs 
                             contendr\'a los nombre de los temas 
                             separados por dos puntos */
	
	Directory_entry();
	Directory_entry(std::string var_name,std::string coeffs);
};

#endif /*DIRECTORY_ENTRY*/
