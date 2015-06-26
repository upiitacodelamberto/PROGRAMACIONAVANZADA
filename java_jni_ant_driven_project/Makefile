libBibliotecaString.so: BibliotecaString.c
	gcc -c -I/usr/lib/jvm/java-6-openjdk/include/ MyCJavaInterface.c -o MyCJavaInterface.o
	ld -G MyCJavaInterface.o -o libMyCJavaInterface.so -lm -lc -lpthread
