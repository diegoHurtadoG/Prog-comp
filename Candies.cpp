//
// Created by diego on 07-10-20.
//

#include <iostream>
#include <math.h>

// Primera liea recibo un t que es la cantidad de n que me van a dar
// desde la segunda en adelante me dan n, tengo que encontrar para cada uno
// x tal que exista k:
//  x + 2x + ... + 2^(k-1)x = n
// => x * (1 + 2 + 4 ... 2^(k-1)) = n
// => x = n / (1 + 2 + ... + 2^(k-1))
// x tiene que ser un int positivo si o si.
// TIENEN que estar todos los terminos de la multiplicacion, no es que se vayan agregando de a uno

//Estrategia: ir haciendo n % (1 + 2 + 4 ...), y cuando eso sea = 0, entonces n / () = x

//Arreglar parametros!
int buscarX(int n, int k, int acc){
    int valor = pow(2, k) + acc;
    if(n % valor == 0){
        std::cout << n/valor << std::endl;
    }
    else{
        return buscarX(n, k + 1, valor);
    }
}

int main(){
    int t;
    std::cin >> t;
    int n[t];

    // Relleno el arreglo n con los t casos
    for(int i = 0; i < t; i++){
        std::cin >> n[i];
    }

    // Para cada t le calculo cuanto vale su x
    for(int j = 0; j < t; j++){
        buscarX(n[j], 1, 1); // El valor de x parte de 1
    }

    return 0;
}