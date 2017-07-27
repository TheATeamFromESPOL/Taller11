#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <sys/time.h>
#include <pthread.h>
 
int aleatorio(int min,int max);
double obtenerTiepoActual();
void * funcion_hilo(void *arg1,void *arg2);

int aleatorio(int min,int max){
	return(rand()%(max-min+1))+min;
}

double obtenerTiepoActual(){
	struct timespec tsp;
	clock_gettime(CLOCK_REALTIME,&tsp);
	double secs = (double)tsp.tv_sec;
	double nano = (double)tsp.tv_nsec / 1000000000.0;
	return secs + nano;
}

/*
void * funcion_hilo(void *arg1,void *arg2){

	int inicial = (long)arg1;
	int final = (long)arg2;

	int i = 0;
	for(i = inicial; i < final; i++){
		sleep(1);
	}

	return (void *)0;	
}
*/

int main(int argc, char *argv[]){
	if (argc!=3){
		printf("%s\n","ingrese correctamente los argumentos");
		return 0;
	}
	int tamanio = atoi(argv[1]);
	int nHilos = atoi(argv[2]);
	int *arreglo;
	arreglo = (int*)malloc(tamanio*sizeof(int));
	
	pthread_t * hilos;
	hilos=(pthread_t*)malloc(nHilos*sizeof(pthread_t));
	
	//Creacion de arreglo
	int i;
	for(i=0; i<tamanio; i++){
	  arreglo[i]=aleatorio(50,100);
	  printf("%i\n",arreglo[i]);
	}
	
	//Creaccion de hilos
	int ini,fin,ent;
	double div;
	int mod;
	div = tamanio/nHilos;
	mod = tamanio%nHilos;
	ent = (int)div;
	if(mod!=0){	
	  ent+=1;
	}
	for(i=0;i<nHilos;i++){
	  ini = ent*i;
	  if(i==(nHilos-1)){
	    fin=tamanio;
	  }
	  else{
	    fin = ent*(i+1);
    }
	  //p_thread(&hilos[i], NULL, funcion_hilo(nHilos*i,nHilos*(i+1),NULL);
	  printf("Inicio: %i    Fin: %i\n",ini,fin);
	}
	
	return 0;
}



