#include <bits/stdc++.h>
using namespace std;
int ans = 0;
vector<int> label;
vector<vector<int>> g;
int mx;
void dfs(int par,int node,int cat,int mx_so_far){
    if(label[node] == 1){
        cat += 1;
    }else{
        cat = 0;
    }
    mx_so_far = max(mx_so_far,cat);
    bool is_leaf = true;
    for(int x:g[node]){
        if(x!=par){
            is_leaf = false;
            dfs(node,x,cat,mx_so_far);
        }
    }
    if(is_leaf and mx_so_far <= mx){
        ans++;
        // cout << node << "\n";
    }
}

int main(){
    int n,m;
    cin >> n >> m;
    mx = m;
    label.resize(n);
    g.resize(n);
    for(int &x:label)
        cin >> x;
    for(int i=0;i<n-1;i++){
        int u,v;
        cin >> u >> v;
        u--,v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(-1,0,0,0);
    cout << ans << "\n";
    return 0;
}