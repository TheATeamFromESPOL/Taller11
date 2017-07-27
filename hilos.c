#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <sys/time.h>
#include <pthread.h>

int aleatorio(int min,int max);
int main(int argc, char *argv[]){
	if (argc!=3){
		printf("%s","ingrese correctamente los argumentos");
		return 0;
	}
	int tamanio = atoi(argv[1]);
	int nHilos = atoi(argv[2]);	
}
