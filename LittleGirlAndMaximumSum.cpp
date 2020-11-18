//
// Created by diego on 13-11-20.
//
// El algoritmo de este ejercicio fue discutido con otros companeros

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
    vector<long long> vectorN; vectorN.resize(n);
    int q;
    cin >> q;
    FenwickTree<long long> FT(n);

    for(int i=0; i<n; i++){
        int val;
        cin >> val;
        vectorN[i] = val;
    }

    for(int i=0; i<q; i++){
        int l;
        int r;
        cin >> l;
        cin >> r;
        FT.addUpdate(l - 1, 1);
        FT.addUpdate(r, -1);
    }

    vector<long long> vectorX;
    vectorX.resize(n);
    for(int i=0; i<n; i++){
        vectorX[i] = FT.query(i);
    }

    sort(vectorN.begin(), vectorN.end());
    sort(vectorX.begin(), vectorX.end());

    long long sum = 0;
    for(int i=0; i<n; i++){
        sum += vectorN[i]*vectorX[i];
    }
    cout << sum << endl;
}