all: jehuty

jehuty: anubis.o jehuty.o main.o 
	gcc anubis.o jehuty.o main.o -o jehuty

anubis.o: anubis.c
	gcc -c anubis.c

jehuty.o: jehuty.c
	gcc -c jehuty.c

main.o: main.c
	gcc -c main.c

clean:
	rm -rf *o jehuty

