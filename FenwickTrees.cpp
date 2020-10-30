//
// Created by diego on 30-10-20.
//
#include<bits/stdc++.h>

using namespace std;


template<class T>
struct FenwickTree{
    vector<T>FT;
    int n;

    // constructor
    FenwickTree(int n) : n(n){
        FT.resize(n + 1);
    }

    // suma acumulada de 0 a pos
    T query(int pos){
        pos ++;
        T sum = 0;
        while(pos > 0){
            sum += FT[pos];
            pos -= (pos & (-pos));
        }
        return sum;
    }

    // suma acumulada de l a r
    T query(int l, int r){
        return query(r) - query(l - 1);
    }

    // Agrega val a la posicion pos
    void addUpdate(int pos, T val){
        pos ++;
        while(pos <= n){
            FT[pos] += val;
            pos += (pos & (-pos));
        }
    }

    // Setea val a la posicion pos
    void setUpdate(int pos, T val){
        addUpdate(pos, val - query(pos, pos));
    }
};


int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n;
    cin >> n;

    FenwickTree<int>FT(n);
    for(int i = 0; i < n; i++){
        int temp;
        cin >> temp;
        FT.addUpdate(i, temp);
    }

    int numero_preguntas;
    cin >> numero_preguntas;
    for(int i = 0; i < numero_preguntas; i++){
        char tipo;
        int x1;
        int x2;
        cin >> tipo >> x1 >> x2;

        if(tipo == 'q'){
            cout << FT.query(x1 - 1, x2 - 1) << "\n";
        }
        else if(tipo == 'u'){
            FT.setUpdate(x1 - 1, x2 - 1);
        }
        else {
            break;
        }
    }
}