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
	int t;
	cin >> t;
	while(t --){
		int n, q; cin >> n >> q;
		FenwickTree<int>FT(n);
		while(q --){
			int a, b, c;
			cin >> a >> b >> c;
			FT.addUpdate(a, c);
			FT.addUpdate(b + 1, -c);
		}
		cin >> q;
		while(q --){
			int pos;
			cin >> pos;
			cout << FT.query(pos) << "\n";
		}
	}
}
