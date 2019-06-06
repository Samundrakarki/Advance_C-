CC      = g++
CFLAGS  = -Wall

all:    Arithmetic Relational Exceptions Iostream
runall: run1 run2 run3 run4
run1:	Arithmetic
	./Arithmetic
run2:	Relational
	./Relational
run3:	Exceptions
	./Exceptions
run4: Iostream
	./Iostream

Arithmetic:   arthemeitc_test.o Fraction.o   
	$(CC) $(CFLAGS) -o Arithmetic arthemeitc_test.o Fraction.o

Relational:   rel_test.o Fraction.o   
	$(CC) $(CFLAGS) -o Relational rel_test.o Fraction.o

Exceptions:   exception_test.o Fraction.o   
	$(CC) $(CFLAGS) -o Exceptions exception_test.o Fraction.o

Iostream: iostream_test.o Fraction.o
	$(CC) $(CFLAGS) -o Iostream iostream_test.o Fraction.o

arthemeitc_test.o: arthemeitc_test.cpp Fraction.h

rel_test.o: rel_test.cpp Fraction.h

exception_test.o: exception_test.cpp Fraction.h

iostream_test.o: iostream_test.cpp Fraction.h 

Fraction.o: Fraction.cpp Fraction.h

clean:
		rm -rf Relational rel_test.o
		rm -rf Arithmetic arthemeitc_test.o
		rm -rf Iostream iostream_test.o
		rm -rf Exceptions exception_test.o
		rm -rf Fraction.o