/***********************************************
    AUTHOR :- Rishav Kumar
    Created at: - 2021-04-02.19:53:05
***********************************************/
#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> g;
int dfs(int root){
    if(g[root].empty())
        return 1;
    int ans = 0;
    for(int ch:g[root]){
        ans = max(ans,dfs(ch));
    }
    return ans + 1;
}
int main(){
    int n;
    cin >> n;
    g.resize(n+1);
    vector<int> boss;
    for(int i=1;i<=n;i++){
        int x;
        cin >> x;
        if(x == -1) boss.push_back(i);
        else g[x].push_back(i);
    }
    int ans = 0;
    for(int r:boss){
        int curr = dfs(r);
        ans = max(ans,curr);
    }
    cout << ans << endl;
    return 0;
}