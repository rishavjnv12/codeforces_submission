#include <bits/stdc++.h>
using namespace std;
void solve(){
	int n,m;
	cin >> n >> m;
	vector<set<int>> g(n+m+2);
	int fake = n+1;
	for(int i=0;i<m;i++){
		int u,v;
		string type;
		cin >> u >> v >> type;
		if(type == "crewmate"){
			g[u].insert(fake);
			g[fake].insert(u);
			g[fake].insert(v);
			g[v].insert(fake);
			fake++;
		}else{
			g[u].insert(v);
			g[v].insert(u);
		}
	}

	vector<int> color(n+m+2,-1);
	int o=0,z=0;
	function<bool(int,int)> dfs = [&](int v,int col){
		color[v] = col;
		if(v<=n){
			if(col) o++;
			else z++;
		}
		for(int x:g[v]){
			if(color[x] == -1){
				if(dfs(x,col^1)==false)
					return false;
			}else{
				if(color[x] == col)
					return false;
			}
		}
		return true;
	};
	bool ok = true;
	int ans = 0;
	for(int i=1;i<=n;i++){
		if(color[i] == -1){
			o = 0;
			z = 0;
			if(dfs(i,0)==false){
				cout << "-1\n";
				return;
			}
			ans += max(o,z);
		}
	}
	cout << ans << "\n";
}


int main(){
	ios_base::sync_with_stdio();
	cin.tie(0);
	int t;
	cin >> t;
	while(t--) solve();
	return 0;
}