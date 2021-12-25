/***********************************************
    AUTHOR :- Rishav Kumar
    Created at: - 2021-05-21.22:05:39
***********************************************/
#include <bits/stdc++.h>
using namespace std;
int par[200001],sz[200001];
int find_set(int v){
    if(par[v] == v)
        return v;
    return par[v] = find_set(par[v]);
}
void unite(int a,int b){
    a = find_set(a);
    b = find_set(b);
    if(a!=b){
        if(sz[a]<sz[b])
            swap(a,b);
        par[b] = a;
        sz[a] += sz[b];
    }
}
void merge(vector<vector<int>>& i) {
    sort(i.begin(),i.end());
    auto it = unique(i.begin(),i.end(),[](vector<int> &a,vector<int> &b){
        if(a[1]>=b[0]){
            a[1]=max(a[1],b[1]);
            return true;
        }
        return false;
    });
    i.resize(it-i.begin());
}
int main(){
    ios_base::
	sync_with_stdio(false);
    cin.tie(NULL);
    int n,m;
    cin >> n >> m;
    for(int i=1;i<=n;i++){
        sz[i] = 1;
        par[i] = i;
    }   
    while(m--){
        int u,v;
        cin >> u >> v;
        unite(u,v);
    }
    vector<int> v;
    for(int i=1;i<=n;i++)
        v.push_back(find_set(i));
    // for(int x:v)
    //     cout << x << " ";
    // cout << "\n";
    map<int,int> first,last;
    for(int i=0;i<n;i++){
        if(first.count(v[i])==0)
            first[v[i]] = i;
        last[v[i]] = i;
    }
    vector<vector<int>> interval;
    for(int i=0;i<n;i++)
        interval.push_back({first[i],last[i]});
    merge(interval);
    int ans = 0;
    for(auto &vv:interval){
        set<int> st;
        for(int i=vv[0];i<=vv[1];i++)
            st.insert(v[i]);
        ans += ((int)st.size()-1);
    }
    cout << ans << "\n";
    return 0;
}