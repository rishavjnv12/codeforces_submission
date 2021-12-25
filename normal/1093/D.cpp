/***********************************************
    AUTHOR :- Rishav Kumar
    Created at: - 2021-06-07.14:16:03
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
int n,m;
const int mod = 998244353;
vector<vector<int>> g;
vector<int> color;
int one = 0,zero = 0;
bool dfs(int node,int col){
	color[node] = col;
	if(col) one++;
	else zero++;
	for(int x:g[node]){
		if(color[x]==col)
			return false;
		else if(color[x]==-1 and dfs(x,col^1)==false)
			return false;
	}
	return true;
}
int power[300005];
int f(int x,int y){
	if(!x)
		return 0;
	if(!y)
		return 1;
	if(y&1){
		int ans = pow(ans,y-1);
		return (ans*x)%mod;
	}else{
		int ans = pow(x,y/2);
		return (ans*ans)%mod;
	}
}
inline int add(int a,int b) {return (a+b)%mod;}
inline int mul(int a,int b) {return (a*b)%mod;}
void solve(){
	cin >> n >> m;
	g.clear();
	g.resize(n+1);
	color.clear();
	color.resize(n+1,-1);
	for(int i=0;i<m;i++){
		int u,v;
		cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	int ans = 1;
	for(int i=1;i<=n;i++){
		if(color[i]==-1){
			one = zero = 0;
			if(dfs(i,0)==false){
				cout << "0\n";
				return;
			}else{
				ans = mul(ans,add(power[one],power[zero]));
			}
		}
	}
	cout << ans << "\n";
	
}
int32_t main(){
	ios_base::
	sync_with_stdio(false);
    cin.tie(NULL);
	power[0] = 1;
	for(int i=1;i<=300003;i++)
		power[i] = (power[i-1]*2)%mod;
	int t = 1;
	read(t);
	for(int testcase = 1;testcase<=t;testcase++){
			#ifdef GOOGLE
				cout << "Case #" << testcase << ": ";
			#endif
			solve();
	}
	return 0;
}