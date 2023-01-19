

all:p1.c pos.h
	gcc -o all p1.c p2.c p3.c -lrt

clean:
	rm *.out all
