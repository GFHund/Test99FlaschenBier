
CC = gcc
DEFAULT_LIB_INSTALL_PATH = /home/tux/Programmieren/st3/Test99FlaschenBier/libcalc.so

studienleistung: calc logconsole logfile
	#$(CC) -o $@ main.c libcalc.so -ldl 
	$(CC) -o $@ main.c -L$(DEFAULT_LIB_INSTALL_PATH) -R$(DEFAULT_LIB_INSTALL_PATH) -ldl
	#$(CC) -o $@ main.c -lcalc -ldl

calc:
	$(CC) -shared -fpic -o libcalc.so calcAreas.h calcAreas.c calcNewton.h calcNewton.c
	#sudo install libcalc.so /usr/lib/studienleistung
	
logconsole:
	$(CC) -o logconsole.so log.h logconsole.c -shared -fpic
	
logfile:
	$(CC) -o logfile.so log.h logfile.c -shared -fpic
	
clean:
	rm *.o
	
debug:
	$(CC) -ggdb -o studienleistungDebug main.c -lcalc -ldl

#logconsole: logconsole.o
#	$(CC) -shared -o logconsole.so logconsole.o
#	
#logconsole.o:
#	$(CC) -c -fpic logconsole.c
#	
#logfile: logfile.o
#	$(CC) -shared -o logfile.so logfile.o
#	
#logfile.o:
#	$(CC) -c -fpic logfile.c
