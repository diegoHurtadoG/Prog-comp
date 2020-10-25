//
// Created by diego on 30-09-20.
//

#include <iostream>
#include <stdlib.h>
#include <math.h>

// Hay n bancas, cada una con a_i personas sentadas
// Vienen m personas y cada una se va a tener que sentar en las bancas disponibles dentro de n
// k es el maximo numero de personas que se sientan en una banca despues de que lleguen las m
// Calcular el k minimo y el k maximo

// El maximo k esta claro que es la banca que tiene mas gente + m
// El minimo k se logra distribuyendo las m personas nivelando siempre la cantidad de gente de las bancas
//  Una idea para esto es sortear, y:
//      Para maximo poner todos los m en el ultimo a_i (maximo)
//      Para minimo empezar a agregar los m desde el principio del arreglo hasta llegar al maximo y de ahi equitativo.

// inputs:
// -> n
// -> m
// -> a_0
// -> ...
// -> a_n-1

// Codigo sacado de cppreference.com, sirve como comparacion en qsort
int compare_ints(const void *a, const void *b){
    int arg1 = *(const int*)a;
    int arg2 = *(const int*)b;

    if(arg1 < arg2) return -1;
    if(arg1 > arg2) return 1;
    return 0;
}

int main(){
    int n;
    std::cin >> n;
    int m;
    std::cin >> m;
    int a[n];

    int iterador = 0;
    int diferencia;
    int kmax;
    int kmin;

    for(int i = 0; i < n; i++){
        std::cin >> a[i];
    }

    qsort(a, n, sizeof(int), compare_ints);

    kmax = a[n - 1] + m;

    while(m > 0 && iterador < (n - 1)){
        diferencia = a[n-1] - a[iterador];
        a[iterador] = a[n-1];
        m -= diferencia; //Arreglar que el m aqui podria ser negativo y eso no puede pasar
        iterador++;
    }


    if (m > 0) {
        float maux = (float) m;
        kmin = a[n - 1] + ceil(maux / n);
    }
    else {
        kmin = a[n - 1];
    }

    std::cout << kmin << " " << kmax;
}

