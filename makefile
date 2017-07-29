all: hilos 

hilos: hilos.c 
	gcc -Wall -g $^ -o $@ -pthread

clean:
	rm -rf cliente servidor
