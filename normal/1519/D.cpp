/***********************************************
    AUTHOR :- Rishav Kumar
    Created at: - 2021-04-29.21:21:30
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
int a[5005],b[5005];
int orig = 0;
int n;
vector<vector<int>> dp;
// dp[i][j] = result after reversing i...j
int rec(int i,int j){
	if(i>j)
		return orig;
	if(dp[i][j]!=-1)
		return dp[i][j];
	int inner = rec(i+1,j-1);
	inner -= (a[i]*b[i]+a[j]*b[j]);
	inner += (a[i]*b[j]+a[j]*b[i]);
	return dp[i][j] = inner;
}
void solve(){
	cin >> n;
	for(int i=0;i<n;i++) cin >> a[i];
	for(int i=0;i<n;i++) cin >> b[i];
	for(int i=0;i<n;i++)
		orig += (a[i]*b[i]);
	dp.resize(n);
	for(auto &v:dp)
		v.assign(n,-1);
	// for(int i=0;i<n;i++) dp[i][i] = orig;
	int ans = orig;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++)
			ans = max(ans,rec(i,j));
	}
	cout << ans << "\n";
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