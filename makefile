
CC = gcc

studienleistung: calc logconsole logfile
	$(CC) -o $@ main.c -lcalc

calc: calcAreas.o calcNewton.o
	$(CC) -shared -o libcalc.so calcAreas.o calcNewton.o
	
calcAreas.o:
	$(CC) -c -fpic calcAreas.c
	
calcNewton.o:
	$(CC) -c fpic calcNewton.c
	
logconsole: logconsole.o
	gcc -shared -o logconsole.so logconsole.o
	
logconsole.o:
	gcc -c -fpic logconsole.c
	
logfile: logfile.o
	gcc -shared -o logfile.so logfile.o
	
logfile.o:
	gcc -c -fpic logfile.c