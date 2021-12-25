/***********************************************
    AUTHOR :- Rishav Kumar
    Created at: - 2021-06-02.21:17:23
***********************************************/
#include <bits/stdc++.h>
#define int long long
// #define GOOGLE
using namespace std;
/* WARSHAW DEBUGGING TEMPLATE (CREDIT:- ERRICHTO) */
#define sim template < class c
#define ris return * this
#define dor > debug & operator <<
#define eni(x) sim > typename \
	enable_if<sizeof dud<c>(0) x 1, debug&>::type operator<<(c i) {
sim > struct rge { c b, e; };
sim > rge<c> range(c i, c j) { return rge<c>{i, j}; }
sim > auto dud(c* x) -> decltype(cerr << *x, 0);
sim > char dud(...);
struct debug {
#ifdef LOCAL
~debug() { cerr << endl; }
eni(!=) cerr << boolalpha << i; ris; }
eni(==) ris << range(begin(i), end(i)); }
sim, class b dor(pair < b, c > d) {
	ris << "(" << d.first << ", " << d.second << ")";
}
sim dor(rge<c> d) {
	*this << "[";
	for (auto it = d.b; it != d.e; ++it)
		*this << ", " + 2 * (it == d.b) << *it;
	ris << "]";
}
#else
sim dor(const c&) { ris; }
#endif
};
#define imie(...) " [" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] "
/***********************************************************/
template<typename T>void read(T &x){cin >> x;}
template<typename T,typename U>void read(T &x,U &y){cin >> x >> y;}
template<typename T>void read(vector<T>& a){for(T& x:a)read(x);}
template<typename T>T cd(T u,T v){return (u+v-1)/v;}
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()
#define vi vector<int>
/***********************************************************/
vector<vector<int>> g,trans;
vector<bool> vis;
stack<int> st;
vector<int> wt;
void dfs(int n){
	vis[n] = true;
	for(int x:g[n]){
		if(!vis[x])
			dfs(x);
	}
	st.push(n);
}
void dfs2(int n,vector<int> &curr){
	vis[n] = true;
	curr.push_back(n);
	for(int x:trans[n]){
		if(!vis[x]){
			dfs2(x,curr);
		}
	}
}
void solve(){
	int n;read(n);
	g.resize(n+1);
	trans.resize(n+1);
	vis.resize(n+1,false);
	wt.resize(n+1);
	for(int i=1;i<=n;i++)
		cin >> wt[i];
	int m;read(m);
	while(m--){
		int u,v;read(u,v);
		g[u].push_back(v);
		trans[v].push_back(u);
	}
	for(int i=1;i<=n;i++){
		if(!vis[i])
			dfs(i);
	}
	vis.assign(n+1,false);
	vector<vector<int>> sccs;
	while(st.size()){
		int i = st.top();
		st.pop();
		if(!vis[i]){
			vector<int> curr;
			dfs2(i,curr);
			sccs.push_back(curr);
		}
	}
	// debug() << imie(sccs);
	int cost = 0,ways = 1;
	int mod = 1e9+7;
	for(auto &v:sccs){
		int mn = INT_MAX;
		map<int,int> mp;
		for(int x:v){
			mn = min(mn,wt[x]);
			mp[wt[x]]++;
		}
		cost += mn;
		ways = (ways*mp[mn])%mod;
	}
	cout << cost << " " << ways << "\n";
}
int32_t main(){
	ios_base::
	sync_with_stdio(false);
    cin.tie(NULL);
	int t = 1;
	// read(t);
	for(int testcase = 1;testcase<=t;testcase++){
			#ifdef GOOGLE
				cout << "Case #" << testcase << ": ";
			#endif
			solve();
	}
	return 0;
}