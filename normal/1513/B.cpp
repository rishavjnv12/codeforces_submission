/***********************************************
    AUTHOR :- Rishav Kumar
    Created at: - 2021-04-11.20:18:14
***********************************************/
#include <bits/stdc++.h>
#define int long long
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
const int mod = 1e9+7;
inline int add(int a,int b){return (a+b)%mod;}
inline int mul(int a,int b){return (a*b)%mod;}
vector<int> fact(2*1e5+5);
int fun(int n){
	return fact[n];
}

void solve(){
	int n;
	read(n);
	vi a(n);read(a);
	sort(all(a));
	vector<int> pref(n),suff(n);
	int total = a[0];
	for(int i=1;i<n;i++)
		total &= a[i];
	int ok = true;
	for(int x:a){
		if((x&total)!=total)
			ok = false;
	}
	map<int,int> mp;
	for(int x:a)
		mp[x]++;
	if(mp[total]<2)
		ok = false;
	if(!ok){
		cout << "0\n";
		return;
	}
	int ans = 1;
	ans = mul(ans,mul(mul(mp[total],mp[total]-1),fact[n-2]));
	// debug() << imie(pref) imie(suff);
	// int ans = 0;
	// for(int i=0;i<n-1;i++){
	// 	if(pref[i]==suff[i+1]){
	// 		int left = i+1;
	// 		int right = n-left;
	// 		ans = add(ans,mul(fact[left],fact[right]));
	// 	}
	// }
	cout << ans << "\n";
}
int32_t main(){
	ios_base::
	sync_with_stdio(false);
    cin.tie(NULL);
	int t = 1;
	fact[0] = 1;
	for(int i=1;i<(int)fact.size();i++)
		fact[i] = mul(fact[i-1],i);
	read(t);
	for(int testcase = 1;testcase<=t;testcase++){
			#ifdef F
					cout << testcase << ":";
			#endif
			solve();
	}
	return 0;
}