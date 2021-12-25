/***********************************************
    AUTHOR :- Rishav Kumar
    Created at: - 2021-12-14.20:46:24
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
	auto sum = [&](int x){
		return (x*(x+1))/2;
	};
	int sm = 0;
	for(int x:a) sm += x;
	if(sm % sum(n)) {
		cout << "NO\n";
		return;
	}
	int all = sm/sum(n);
	vector<int> ans(n);
	int rest = 0;
	for(int i=1;i<n;i++){
		int here = a[i] - a[i-1];
		int curr = all - here; // (n)*b[i];
		if(curr % (n)){
			cout << "NO\n";
			return;
		}
		ans[i] = curr / (n);
		rest += ans[i];
	}
	ans[0] = all-rest;
	for(int x:ans){
		if(x<=0){
			cout << "NO\n";
			return;
		}
	}
	cout << "YES\n";
	for(int x:ans){
		cout << x << " ";
	}
	cout << "\n";
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