/***********************************************
    AUTHOR :- Rishav Kumar
    Created at: - 2021-10-19.17:54:21
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
	int sum = 0;
	for(int x:a)
		sum += x;
	if(sum % 3){
		cout << "0\n";
		return;
	}
	int target = sum/3;
	int ans = 0;
	vector<int> pref(n);
	partial_sum(all(a),pref.begin());
	int cnt = 0;
	for(int x:pref)
		cnt += (x == 2*target);
	
	if(target == 0){
		int y = 0;
		for(int x:pref)
			y += (x == 0);
		// 1+2+3+.....+(y-2)
		// (y-2)*(y-1)/2
		cout << ((y-2)*(y-1))/2 << "\n";
		return;

		
	}
	for(int x:pref){
		if(x == 2*target)
			cnt--;
		else if(x == target)
			ans += cnt;
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