INCLUDE_DIRS:= ./BibliotecaString/include /usr/lib/jvm/java-6-openjdk/include/
SOURCE_DIRS:= ./BibliotecaString/src/
CFILES:= bibliotecastring.cpp
#ASM_FILES:= startup_ARMCM4.S
INCLUDE_FLAGS:=$(patsubst %,-I%,$(INCLUDE_DIRS))
#TCHIP=TM4C123GH6PM
#CC=arm-none-eabi-gcc
#CC=avr-gcc
#CC=gcc
CC=g++
CFLAGS=-g -Wall -fPIC

#ld -G BibliotecaString/objectfiles/*.o -o BibliotecaString/lib/libBibliotecaString.so -lc -lpthread
#ld: BibliotecaString/objectfiles/bibliotecastring.o: relocation R_X86_64_PC32 against symbol `_ZN7JNIEnv_17GetStringUTFCharsEP8_jstringPh' can not be used when making a shared object; recompile with -fPIC
#ld: final link failed: Bad value
#make: *** [libBibliotecaString.so] Error 1    (2015.07.02)

#CPPFLAGS= $(INCLUDE_FLAGS) -D__AVR_LIBC_DEPRECATED_ENABLE__
CPPFLAGS= $(INCLUDE_FLAGS)
vpath %.h $(INCLUDE_DIRS)
vpath %.cpp *.o $(SOURCE_DIRS)
COBJECTS:= $(patsubst %.cpp,%.o,$(CFILES))

all: libBibliotecaString.so
##libBibliotecaString.so: bibliotecastring.cpp
#libBibliotecaString.so: $(COBJECTS)
# gcc -c -I/usr/lib/jvm/java-6-openjdk/include/ MyCJavaInterface.c -o MyCJavaInterface.o
# gcc -c -I MyCJavaInterface.c -o MyCJavaInterface.o
# ld -G MyCJavaInterface.o -o libMyCJavaInterface.so -lm -lc -lpthread
$(COBJECTS): %.o: %.cpp
	mkdir -p BibliotecaString/objectfiles
	$(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o BibliotecaString/objectfiles/$@

libBibliotecaString.so: $(COBJECTS)
	mkdir -p BibliotecaString/lib
	ld -G BibliotecaString/objectfiles/*.o -o BibliotecaString/lib/$@ -lc -lpthread 

.PHONY: clean rebuild
clean:
	rm -frv BibliotecaString/lib/
	rm -frv BibliotecaString/objectfiles/

rebuild: clean all
