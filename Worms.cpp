//
// Created by diego on 26-09-20.
//

#include <iostream>
#include <stdlib.h>
#include <vector>

// - n pilas ordenadas de gusanos tal que n[i] tiene a_i gusanos
// - Todos los gusanos tienen etiqueta con numeros consecutivos
// - En la primera pila tienen 1 ... a_1, en la segunda a_1 + 1 ... a_1 + a_2
// - Hay que comerse solo los que tienen la etiqueta que dice el input
// - El output son EL INDICE DE PILAS que tienen los gusanos que nos dice el input

// Estrategia:
//  -> Hacer un arreglo con las cantidades acumuladas de cada pila
//  -> Ir descartando intervalos hasta algun valor que sea menor al que busco pero que el sgte sea mayor
//  -> n = 3; a = 8 5 6; m = 1; e = 17;
//  -> Me armo el arrego: [8 , (8+5), (anterior + 6)] -> [8, 13, 19]
//  -> En el de la mitad pregunto a[k] < e?
//      -> Busco a la derecha
//  -> Sino, busco en la izquierda
//  -> Retorno cuando queda 1 valor.

int main(){

    int n; // Cantidad de pilas
    std::cin >> n;
    int a[n]; //Arreglo de valores de pilas
    int acumulador = 0;

    // Creo arreglo de valores, funciona
    for(int i = 0; i < n; i++){
        std::cin >> a[i];
        a[i] = a[i] + acumulador;
        acumulador = a[i];
    }

    int w;
    std::cin >> w;
    int mid, low, high;

    for(int i = 0; i < w; i++){
        int e;
        std::cin >> e;

        low = 0;
        high = n;
        while(low < high){
            int mid = (low + high) / 2;

            // Reviso el primero
            if(a[mid] < e){
                low = mid + 1;
            }
            else{
                high = mid;
            }
        }
        std::cout << high + 1 << std::endl;
    }
    return 0;
}
