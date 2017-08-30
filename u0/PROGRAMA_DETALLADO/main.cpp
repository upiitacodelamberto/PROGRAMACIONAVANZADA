#include <stdlib.h>
#include <locale.h>
#include "tddprogdetallado.h"
int main(){
	struct prog_detallado *SOTR  = (struct prog_detallado *)
				malloc(sizeof(struct prog_detallado));
	prog_detallado(SOTR);
	return 0;
}
