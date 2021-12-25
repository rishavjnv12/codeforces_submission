/***********************************************
    AUTHOR :- Rishav Kumar
    Created at: - 2021-03-17.19:59:19
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
template<typename T>T cd(T u,T v){return (u+v-1)/2;}
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()
#define vi vector<int>
/***********************************************************/
void solve(){
	int n,k;read(n,k);
	vi a(n);read(a);
	vector<int> mp(k);
	for(int x:a)
		mp[x%k]++;
	int ans = 0;
	if(mp[0]!=0){
		ans++;
		mp[0] = 0;
	}
	if(k%2==0 and mp[k/2]){
		ans++;
		mp[k/2] = 0;
	}
	for(int i=1;2*i<k;i++){
		int l = mp[i];
		int r = mp[k-i];
		if(!l or !r) continue;
		if(l==r){
			ans++;
			mp[i] = 0;
			mp[k-i] = 0;
		}else if(l>r){
			mp[i] -= (mp[k-i]+1);
			mp[k-i] = 0;
			ans++;
		}else{
			mp[k-i] -= (mp[i]+1);
			mp[i] = 0;
			ans++;
		}
	}
	// cout << ans << endl;
	debug() <<imie(mp);
	for(int x:mp)
		ans+=x;
	cout << ans << endl;
}
int32_t main(){
	int t = 1;
	read(t);
	for(int testcase = 0;testcase<t;testcase++){
			#ifdef F
					cout << testcase << ":";
			#endif
			solve();
	}
	return 0;
}