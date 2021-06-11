//
// Created by diego on 11-12-20.
//

// No es mio original, no lo pude hacer y pedi ayuda a un companero
// Me explico la metodologia de como lo hizo el mientras me explicaba con su codigo

#include<bits/stdc++.h>
using namespace std;

vector<int> getAllIntDivisors(int n){
    vector<int> vector;
    for (int i = 1; i <= n; i++){
        if (n%i == 0){
            vector.push_back(i);
        }
    }
    return vector;
}

bool is_divisor(string &sub, string &s){
    // abcdabcd
    // abcd
    // (0, 3)
    // (4, 7)
    int n = s.size()/sub.size();
    for (int i = 0; i < n; i++){
        string new_sub = s.substr(i*sub.size(), sub.size());
        // cout << new_sub << endl;
        if(sub != new_sub){
            return false;
        }
    }
    return true;
}

vector<string> getDivisor(string &s){
    vector<int> divisores = getAllIntDivisors(s.size());
    vector<string> output;
    for(int i = 0; i < divisores.size(); i++){
        string sub = s.substr(0, divisores[i]);
        if(is_divisor(sub, s)){
            output.push_back(sub);
        }

    }
    return output;
}


int main(){
    string s, t; cin >> s >> t;
    vector<string> div_s = getDivisor(s);
    vector<string> div_t = getDivisor(t);
    int inter = 0;
    if(div_s.size() > div_t.size()){
        sort(div_t.begin(), div_t.end());
        for(int i = 0; i < div_s.size(); i++){
            if(binary_search(div_t.begin(), div_t.end(), div_s[i])){
                inter+=1;
            }
        }
    }else{
        sort(div_s.begin(), div_s.end());
        for(int i = 0; i < div_t.size(); i++){
            if(binary_search(div_s.begin(), div_s.end(), div_t[i])){
                inter+=1;
            }
        }
    }
    cout << inter << "\n";
}