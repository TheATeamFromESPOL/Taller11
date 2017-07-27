#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <sys/time.h>
#include <pthread.h>

int aleatorio(int min,int max);
double obtenerTiepoActual();

int aleatorio(int min,int max){
	return(rand()%(max-min+1))+min;
}

double obtenerTiepoActual(){
	struct timespec tsp;
	clock_gettime(CLOCK_REALTIME,&tsp);
	double secs = ();
	double nano = ();
	return secs + nano;
}

int main(int argc, char *argv[]){
	if (argc!=3){
		printf("%s\n","ingrese correctamente los argumentos");
		return 0;
	}
	int tamanio = atoi(argv[1]);
	int nHilos = atoi(argv[2]);
	int *arreglo;
	arreglo = (int*)malloc(tamanio*sizeof(int));
	
}


