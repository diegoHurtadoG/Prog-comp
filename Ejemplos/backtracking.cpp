#include <bits/stdc++.h>

using namespace std;
int n;

vector<vector<int> >S;	// Conjunto de objetos

vector<bool>usados;		// Indica los numeros que ya estan en el objeto parcial

void backtracking(vector<int> &parcial){
	if (parcial.size() == n){		// Si es objeto final u hoja del arbol de construccion
		S.push_back(parcial);		// Se agrega al conjunto de objetos (vector en verdad)
		return ;
	}
	for (int agregar = 1; agregar <= n; agregar ++){		// Se itera sobre todas las formas de extender el objeto parcial
		if (!usados[agregar]){
			usados[agregar] = 1;
			parcial.push_back(agregar);							// Agrega el elemento agregar al final del vector
			backtracking(parcial);								// Se llama backtracking
			parcial.pop_back();									// Elimina la ultima posicion de un vector
			usados[agregar] = 0;
		}
	}
}


int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    usados.resize(n + 1, false);
    vector<int>parcial;
    backtracking(parcial);
    for (auto &p : S){		// Itera sobre todos los objetos de S
    	for (int i = 0; i < n; i ++){
    		cout << p[i] << " ";
    	}
    	cout << "\n";
    }
    return 0;
}