#include <ctime>  // biblioteca de funciones del reloj
#include <iostream>  // Funciones E/S
#include <math.h>  // Funciones matematicas
 
using namespace std;
 
void mostrarTiempo(clock_t tiempo);
 
int main(){
    clock_t tiempo = clock();    // iniciar el reloj para caluclar el tiempo
    // Variables
    long long i = 0;
    double sum = 0;
    // Inicia el ciclo de alrededor de 28 segundos
    for (i = 1; i < 1000000000; i++){
    	// Función que geneal alta carga de procesamiento
    	// Tomamos un número double (decimal largo) y le aplicamos logaritmo natural
        sum = sum + log(double(i));
    }
 
	// Mostramos el tiempo que le tomó ejecutar
    mostrarTiempo(tiempo);
 
 	// Salimos
    cout << "Pulse para salir...";
    cin.get();
    return 0;
}
 
// Función que calcula el tiempo de ejecucción
void mostrarTiempo(clock_t tiempo){
    tiempo = clock() - tiempo;
    cout << endl << "Tiempo de ejecucion es " << double(tiempo) / CLOCKS_PER_SEC << " seg." << endl;
}
