#include <windows.h>  // Biblioteca para la funci�n sleep()
#include <process.h>  // Biblioteca para la funci�n _beginthread()
#include <time.h>  // Biblioteca para las funciones del reloj
#include <stdio.h>  // Biblioteca para la funci�n getchar()

void task1(void *);

int main(int, char**)
{
	// Variable requerida para la funci�n _beginthread
    int ThreadNr;
    
    // Coloca la cantidad de nucleos de tu equipo
    // Puedes jugar con valores altos como 10 o 20 y ver�s que tu equipo ocupa el 100% del CPU
    int nucleos = 30;
    
    // Se realiza el separado por hilos de ejecucci�n por numero de nucleos
    for(int i=0; i < nucleos; i++) _beginthread( task1, 0, &ThreadNr );

	// Escribe cualquiere tecla para terminar
    (void) getchar();
    return 0;
}

void task1(void *)
{
	// Ciclo infinito para utilizar le procesador
	// Termina el programa presionando la tecla Enter
    while(1)
    {
    	// Obtenemos el reloj actual + 50
        clock_t wakeup = clock() + 50;
        
        // Hacemo 50 ticks de reloj que ocupa uso de CPU
        while(clock() < wakeup) {}
        
        // Despu�s de 50 ticks, dormimos 50 milisegundos para darle un respiro al procesador 
        // y no trabar el equipo
        Sleep(50);
    }
}


