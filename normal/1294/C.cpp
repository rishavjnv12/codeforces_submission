/***********************************************
    AUTHOR :- Rishav Kumar
    Created at: - 2021-03-30.00:28:53
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

void solve(){
	int n;read(n);
	set<int> used;
	for (int i = 2; i * i <= n; ++i) {
		if (n % i == 0 && !used.count(i)) {
			used.insert(i);
			n /= i;
			break;
		}
	}
	for (int i = 2; i * i <= n; ++i) {
		if (n % i == 0 && !used.count(i)) {
			used.insert(i);
			n /= i;
			break;
		}
	}
	if (used.size() < 2 || used.count(n) || n == 1) {
		cout << "NO" << endl;
	} else {
		cout << "YES" << endl;
		used.insert(n);
		for (auto it : used) cout << it << " ";
		cout << endl;
	}
}
int32_t main(){
	ios_base::
	sync_with_stdio(false);
    cin.tie(NULL);
	int t = 1;
	read(t);
	for(int testcase = 1;testcase<=t;testcase++){
			#ifdef F
					cout << testcase << ":";
			#endif
			solve();
	}
	return 0;
}