/***********************************************
    AUTHOR :- Rishav Kumar
    Created at: - 2021-07-14.20:22:34
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
void solve(){
	int n;read(n);
	vi a(n);read(a);
	int ans = 2*n - 1;
	for(int i=0;i<n-2;i++){
		int p = a[i],q = a[i+1],r = a[i+2];
		if((q>=p and r>=q) or (p>=q and q>=r)){

		}else{
			ans++;
		}
	}
	for(int i=0;i<n-3;i++){
		int p = a[i],q = a[i+1],r = a[i+2], s = a[i+3];
		// 1110, 1101, 1011, 0111
		bool flag1 = (p>=q and q>=r) or (p<=q and q<=r);
		bool flag2 = (p>=q and q>=s) or (p<=q and q<=s);
		bool flag3 = (p>=r and r>=s) or (p<=r and r<=s);
		bool flag4 = (q>=r and r>=s) or (q<=r and r<=s);
		if(!flag1 and !flag2 and !flag3 and !flag4)
			ans++;
		
		
	}
	cout << ans << "\n";
}
// efhrgiweyrgyqw4ctub4rf46
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