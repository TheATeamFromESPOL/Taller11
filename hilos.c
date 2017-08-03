#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <sys/time.h>
#include <pthread.h>

//Definición estructura
typedef struct estructuraTaller11{
	
	int inicio;
	int final;
	int *arreglo;

}parametros;

//Definición funciones
int aleatorio(int min,int max);
double obtenerTiempoActual();
void * funcion_hilo(void *estructura);

int aleatorio(int min,int max){
	return(rand()%(max-min+1))+min;
}

double obtenerTiempoActual(){
	struct timespec tsp;
	clock_gettime(CLOCK_REALTIME,&tsp);
	double secs = (double)tsp.tv_sec;
	double nano = (double)tsp.tv_nsec / 1000000000.0;
	return secs + nano;
}

void * funcion_hilo(void *estructura){
	
	parametros *param = (parametros *)estructura;
	int ini = param->inicio;
	int fin = param->final;
	int *arreglo = param->arreglo; 

	int i = 0;
	long hue = 0;
	for(i = ini; i < fin; i++){
		hue += arreglo[i];
	}
	return (void *)hue;	
}


int main(int argc, char *argv[]){
	if (argc!=3){
		printf("%s\n","Ingrese correctamente los argumentos");
		return 0;
	}
	double tiempoInicial = obtenerTiempoActual();
	srand(time(NULL));

	long suma = 0;
	int tamanio = atoi(argv[1]);
	int nHilos = atoi(argv[2]);
	int *arreglo;
	arreglo = (int*)malloc(tamanio*sizeof(int));
	
	pthread_t * hilos;
	hilos=(pthread_t*)malloc(nHilos*sizeof(pthread_t));
	
	//Creacion de arreglo
	int i;
	for(i=0; i<tamanio; i++){
		int r=aleatorio(1,10);
		arreglo[i]=r;
	}
	//--printf("\n");
	
	//Creaccion de hilos
	int ini,fin,div;
	div = (int)tamanio/nHilos;
	//--printf("div: %i  mod: %i\n",div,mod);	
	for(i=0;i<nHilos;i++){
		ini=div*i;
		if(i!=(nHilos-1))
			fin=div*(i+1);
		else
			fin=tamanio;
		//Creacion estructura con parámetros
		parametros *param = (parametros *)malloc(sizeof(parametros *));
		param->inicio = ini;
		param->final = fin;
		param->arreglo = arreglo;
		
		//Creacion del hilo con proceso a ejecutar
	  int hilo = pthread_create(&hilos[i], NULL, funcion_hilo,(void *)param);
		if(hilo<0){
			printf("Error creando hilo.");
			return 0;
		}
	}
	for(i=0;i<nHilos;i++){
		void * sumaHilo = malloc(sizeof(long));
		pthread_join(hilos[i],sumaHilo);
		suma += *((long*) sumaHilo); 
	}
	double tiempoFinal = obtenerTiempoActual();
	printf("Suma total de componentes en el arreglo: %li\n",suma);
	printf("Al usar %d hilos\nSe hizo un tiempo de %f \n ",nHilos,tiempoFinal-tiempoInicial);
	
	return 0;
}



