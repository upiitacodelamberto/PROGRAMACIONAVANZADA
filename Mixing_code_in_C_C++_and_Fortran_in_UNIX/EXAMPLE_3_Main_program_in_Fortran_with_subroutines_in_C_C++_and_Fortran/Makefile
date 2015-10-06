G77=f77
RM=rm
fprogram: fprogram.o ffunction.o cppfunction2.o cfunction2.o
	${G77} -lc -o $@ fprogram.o ffunction.o cppfunction2.o cfunction2.o

clean:
	${RM} -v *.o fprogram
