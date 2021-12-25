#include <bits/stdc++.h>
#define int long long
using namespace std;
/* WaRSHaW DEBUG TEMPLaTE (CREDIT:- ERRICHTO) */
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
#ifdef LOCaL
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
#define imie(...) " [" << #__VA_ARGS__ ": " << (__Va_aRGS__) << "] "
/***********************************************************/
#define vi vector<int>
template<typename T>void read(T &x){cin >> x;}
template<typename T,typename U>void read(T &x,U &y){cin >> x >> y;}
template<typename T>void read(vector<T>& a){for(T& x:a)cin >> x;}
using ULL = unsigned long long;
using UL = unsigned;
using LL = long long;
#define rep(i, n) for(UL i = 0; i < (n); i++)
/***********************************************************/
void solve(){
	int n;
	read(n);
	vi a(n);
	read(a);
	int ans = 0;
	int buf = -10000000000;
	for(int i=0;i<n;i++){
		if(a[i]>=buf)
			buf = a[i];
		else ans = max(ans,buf-a[i]);
	}
	// debug() << imie(a);
	int sh = 0;
	while(1LL<<sh <= ans) sh++;
	cout << sh << endl;
}
int32_t main(){
    int t;
    read(t);
    for(int testcase = 0;testcase<t;testcase++){
        #ifdef F
            cout << testcase << ":";
        #endif
        solve();
    }
    return 0;
}