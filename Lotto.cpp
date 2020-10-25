//
// Created by diego on 14-10-20.
//

#include<bits/stdc++.h>
using namespace std;


/*
    Este problema trate de hacerlo solo, llegue a cosas parecidas
    pero nunca a la correcta, por lo que lo discuti con un companero
    que ya lo habia terminado y me lo explico bien
*/

int current_print = 0;

void backtracking(int k, vector<int> &partial, vector<int> &S, vector<bool> &used, int index){
    if (partial.size() == 6){
        for (int i = 0; i < 6; i++){
            if (i > 0){
                cout << " ";
            }
            cout << partial[i];
        }
        cout << '\n';
    }
    else{
        for (int i = index; i < k; i++){
            if (!used[i]){
                used[i] = true;
                partial.push_back(S[i]);
                backtracking(k, partial, S, used, i+1);
                partial.pop_back();
                used[i] = false;
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    int k;
    cin >> k;
    while( k != 0 ){
        vector<int> S(k);
        for (int m = 0; m < k; m++){
            cin >> S[m];
        }
        vector<bool> used(k, false);
        vector<int> partial;
        backtracking(k, partial, S, used, 0);
        cin >> k;
        if ( k!= 0 ){
            cout << "\n";
        }
    }
    return 0;
}