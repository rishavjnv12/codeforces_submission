/***********************************************
    AUTHOR :- Rishav Kumar
    Created at: - 2021-05-21.21:18:13
***********************************************/
#include <bits/stdc++.h>
#define int long long
using namespace std;
int par[200001],sz[200001];
int comp;
int find_set(int v){
    if(par[v] == v)
        return v;
    return par[v] = find_set(par[v]);
}
void unite(int a,int b){
    a = find_set(a);
    b = find_set(b);
    if(a!=b){
        comp--;
        if(sz[a]<sz[b])
            swap(a,b);
        par[b] = a;
        sz[a] += sz[b];
    }
}
int32_t main(){
    int n;
    cin >> n;
    comp = n;
    for(int i=0;i<n;i++){
        par[i] = i;
        sz[i] = 1;
    }
    map<char,int> mp;
    for(int i=0;i<n;i++){
        string s;
        cin >> s;
        for(char c:s){
            if(mp.count(c))
                unite(i,mp[c]);
            mp[c] = i;
        }
    }
    cout << comp << "\n";
    return 0;
}