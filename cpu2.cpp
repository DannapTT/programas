#include <windows.h> //Biblioteca para la funcion sleep()
#include <process.h> //Biblioteca para la funcion _beginthread()
#include <time.h> //Biblioteca para las funciones del reloj
#include <stdio.h> //Biblioteca para la funcion getchar ()

void task1(void*);
int main(int, char**)
{
	//variable requerida para la funcion _beginthread
	int ThreadNr;
	//coloca la cantidad de nucleos de tu equipo
	//puedes jugar con valores altos como 10 o 20 y veras que tu equipo ocupa el 100% del CPU
	int nucleos = 20;
	
	//se realizaa el separador por hilos de ejecucion por numero de nucleos 
	for(int i=0; i < nucleos; i++) _beginthread( task1, 0, &ThreadNr);
	//escribe cualquier tecla para terminar
	(void) getchar();
	return 0;
}
void task1(void*)
{
	//ciclo infinito para utilizar el procesador
	//termina el programa presionando la tecla Enter
	while(1)
	{
		//btenemos el reloj actual + 50
		clock_t wakeup = clock() + 50;
		//hacemos 50 ticks de reloj que ocupa uso de CPU
		while(clock() < wakeup) {}
		
		//despues de 50 tickes, dormimos 50 milisegundos para darle un respiro al procesador
		//y no traba el equipo
		Sleep(50);
	}
}
