/***********************************************
    AUTHOR :- Rishav Kumar
    Created at: - 2021-06-04.20:35:32
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
int f(int n){
	return (n*(n+1))/2;
}
void solve(){
	string s;
	cin >> s;
	const int n = s.size();
	// vi f(n);
	// for(int i=0;i<n;i++){
	// 	f[i] = s[i] == '?';
	// }
	// partial_sum(all(f),f.begin());
	// int i=0,j = 0;
	// int opar = -1,zpar = -1;
	// while(i<n and j<n){
	// 	while(s[j]=='?') j++;

	// }
	vector<vector<int>> dp(n,vector<int> (2,0));
	if(s[0] == '?') dp[0] = {1,1};
	if(s[0] == '1') dp[0] = {0,1};
	if(s[0] == '0') dp[0] = {1,0};
	for(int i=1;i<n;i++){
		if(s[i]=='?'){
			dp[i][0] = (dp[i-1][1]+1);
			dp[i][1] = (dp[i-1][0]+1);
		}else if(s[i]=='0')
			dp[i][0] = (dp[i-1][1]+1);
		else dp[i][1] = (dp[i-1][0]+1);
	}
	int ans = 0;
	for(int i=0;i<n-1;i++){
		auto &v = dp[i],w = dp[i+1];
		if(max(v[0],v[1])+1 != max(w[0],w[1])){
			ans += f(max(v[0],v[1]));
			ans -= f(max(w[0],w[1])-1);
		}
	}
	ans += f(max(dp[n-1][0],dp[n-1][1]));
	cout << ans << "\n";
	debug() << imie(dp);
}
int32_t main(){
	ios_base::
	sync_with_stdio(false);
    cin.tie(NULL);
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