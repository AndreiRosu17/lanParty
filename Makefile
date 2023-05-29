.phony: build run clear

build: main.o functii.o
		gcc main.o functii.o -o lanParty
		
main.o: main.c
		gcc -c main.c

functii.o: functii.c
		gcc -c functii.c

run:
		./lanParty date/t1/c.in date/t1/d.in out.txt

clear:
		rm lanParty