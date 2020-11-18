//
// Created by diego on 13-11-20.
//
#include<iostream>
#include<bits/stdc++.h>
#include<string>

using namespace std;

template<class T>
struct FenwickTree{
    vector<T>FT;
    int n;

    // constructor
    FenwickTree(int n) : n(n){
        FT.resize(n + 1, 0);
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
    long long c = 1;
    long long n;
    cin >> n;
    do {
        FenwickTree<long long>FT(n); // Aqui voy a ir guardando las resistencias.
        for(long long i = 0; i < n; i++){ // Lleno el fenwick tree
            long long temp;
            cin >> temp;
            FT.addUpdate(i, temp);
        }
        // Ya llene el FT con las n primeras resistencias
        string instruccion;
        if(c != 1){
            cout << "\n";
        }
        cout << "Case " << c << ":" << "\n";
        while (true){
            long long x1, x2;
            cin >> instruccion;
            if (instruccion == "END"){
                //cout << "\n";
                break;
            }
            cin >> x1 >> x2;
            if (instruccion == "M"){
                cout << FT.query(x1 - 1, x2 - 1) << "\n";
            }
            else{
                FT.setUpdate(x1 - 1, x2);
            }
        }
        c++;
        cin >> n;
    } while(n != 0);
};