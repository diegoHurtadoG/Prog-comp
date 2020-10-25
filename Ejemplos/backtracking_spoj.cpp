#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

ll K;
vector<ll>V;


// Guardamos la suma parcial y el vector de numeros usados
bool backtracking(vector<ll>&parcial, vector<bool>&used, ll sum){
	if (parcial.size() == 10){
		return true;
	}
	for (ll i = 0LL; i < 10LL; i ++){
		ll sum2 = sum + i * V[parcial.size()];
		if (!used[i] and sum2 <= K){	//podando
			used[i] = 1;
			parcial.push_back(i);
			if (backtracking(parcial, used, sum2)) {	// Si ya encontramos una solucion terminamos
				return true;
			}
			parcial.pop_back();
			used[i] = 0;
		}
	}
	return false;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    int t;
    cin >> t;
    V.resize(10);
    while(t --){
    	for (int i = 0; i < 10; i ++){
    		cin >> V[i];
    	}
    	cin >> K;
    	vector<bool>used(10, false);
    	vector<ll>parcial;
    	if (backtracking(parcial, used, 0LL)){
    		for (int i = 0; i < 10; i ++){
    			if (i > 0){
    				cout << " ";
    			}
    			cout << parcial[i];
    		}
    		cout << "\n";
    	}
    	else cout << "-1\n";
    }
    return 0;
}