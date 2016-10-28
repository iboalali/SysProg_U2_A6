OBJECTS = main.o PersonenDaten.o StringFuncs.o
CPPFLAGS = -g -Wall

sortedlist : $(OBJECTS)
	gcc $(CPPFLAGS) -o sortedlist $(OBJECTS)

main.o : main.c PersonenDaten.h StringFuncs.h 
	gcc $(CPPFLAGS) -c main.c

PersonenDaten.o : PersonenDaten.c PersonenDaten.h
	gcc $(CPPFLAGS) -c PersonenDaten.c

StringFuncs.o : StringFuncs.c StringFuncs.h
	gcc $(CPPFLAGS) -c StringFuncs.c

clean:
	rm sortedlist $(OBJECTS)		
