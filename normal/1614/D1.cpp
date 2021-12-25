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
void read(){}
template <typename T, typename... Types>
void read(T &var1, Types&... var2){cin >> var1;read(var2...);}
template<typename T>void read(vector<T>& a){for(T& x:a)read(x);}
template<typename T>T cd(T u,T v){return (u+v-1)/v;}
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()
#define vi vector<int>
/***********************************************************/

void solve(){
	int n;read(n);
	vi a(n);read(a);
	const int mx = *max_element(all(a));
	vector<int> cnt(mx+1);
	vector<int> mp(mx+1);
	for(int x:a) mp[x]++;
	for(int i=1;i<=mx;i++){
		for(int j=i;j<=mx;j+=i){
			cnt[i] += mp[j];
		}
	}
	vector<int> dp(mx+1);
	for(int i=mx;i>=1;i--){
		dp[i] = i*cnt[i];
		for(int j=i*2;j<=mx;j+=i)
			dp[i] = max(dp[i],dp[j]+(cnt[i]-cnt[j])*i);
	}
	cout << dp[1] << endl;
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