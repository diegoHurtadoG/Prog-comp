#include<bits/stdc++.h>
using namespace std;
const int MAXN = 1e6;
const ll z = 131, MOD = 1e9+21;
ll Z[MAXN+1];

//precalcula las potencias de (z^i)%MOD (importante hacer antes de hacer rolling hashing)
void fillZ() {
  Z[0] = 1;
  for(int n = 1; n <= MAXN; ++n)
    Z[n] = z*Z[n-1]%MOD;
}

struct RollingHashing {
  vector<ll> H;

  //crea los hash del string s
  RollingHashing(string &S) {
    int N = S.length();
    H.resize(N+1);
    H[N] = 0;
    for(int i = N-1; i >= 0; --i)
      H[i] = (S[i] + z*H[i+1])%MOD;
  }

  //entrega el hash del string s desde el indice i de tamano k
  ll hash(int i, int k) {
    ll ans = (H[i] - Z[k]*H[i+k]%MOD);
    return ans >= 0 ? ans : ans + MOD;
  }
};
