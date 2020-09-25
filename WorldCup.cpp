//
// Created by diego on 23-09-20.
//

#include <iostream>
#include <stdlib.h>

// Parto con n entradas, cada entrada con x personas
// Cada ciclo, todas las entradas dejan pasar a una persona, y Allen se mueve 1 a la derecha
// idea: Buscar la entrada con el minimo de personas, restarle ese numero a todas las entradas
//          ver con % donde esta Allen cuando se resta eso (pasaron min(x) ciclos) y de ahi que
//          de alguna forma sepa donde esta el 0, y que vea si sigue adelante encuentra otro antes o
//          da la vuelta entera.

int main(){
    //Variables iniciales
    int n;
    int min = INT32_MAX;
    std::cin >> n;
    int queues[n];
    int counter = 0;
    int position;

    // Defino el arreglo a medida que agrego elementos, defino el minimo
    for (int i = 0; i < n; i++) {
        std::cin >> queues[i];
        if (queues[i] < min)
            min = queues[i];
    }

    // Le resto el minimo a todos los elementos
    for (int i = 0; i < n; i++){
        queues[i] -= min;
    }

    // Posicion en la que quedo luego de restar el minimo
    position = min % n;

    // Desde la posicion, hago un ciclo en el que:
    //  - Resto el contador al queue
    //  - Pregunto si es cero -> gane
    //  - Sumo 1 al contador y muevo la posicion
    //  - Repito el ciclo
    for (int i = 0; i < n + 1; i++){
        queues[position] -= counter;
        if (queues[position] <= 0){
            std::cout << position + 1 << std::endl;
            break;
        }
        else{
            counter += 1;
            position = (position + 1) % n;
        }
    }

}
