#include <stdio.h>
void ffunction_(float*, float*);
void cppfunction(float*, float*);
void cfunction(float*, float*);
int main(void) {
  float a=1.0, b=2.0;

  printf("Before running Fortran function:\n");
  printf("a=%f\n",a);
  printf("b=%f\n",b);
  ffunction_(&a,&b);
  printf("After running Fortran function:\n");
  printf("a=%f\n",a);
  printf("b=%f\n",b);

  printf("Before running C++ function:\n");
  printf("a=%f\n",a);
  printf("b=%f\n",b);
  cppfunction(&a,&b);
  printf("After running C++ function:\n");
  printf("a=%f\n",a);
  printf("b=%f\n",b);

  printf("Before running C function:\n");
  printf("a=%f\n",a);
  printf("b=%f\n",b);
  cfunction(&a,&b);
  printf("After running C function:\n");
  printf("a=%f\n",a);
  printf("b=%f\n",b);

  return 0;
}
