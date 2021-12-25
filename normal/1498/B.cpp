/***********************************************
    AUTHOR :- Rishav Kumar
    Created at: - 2021-03-29.20:11:57
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
int f(int n){
	int pos = 0;
	while((n&(1<<pos))==0) pos++;
	return pos;
}
void solve(){
	int n,w;read(n,w);
	vi a(n);read(a);
	vi bits(20);
	for(int x:a){
		int pos = 0;
		while((x&(1<<pos))==0) pos++;
		bits[pos]++;
	}
	int ans = 1;
	set<int> st(all(a));
	int rem = w;
	while(st.size()){
		int val = -1;
		for(int x:st){
			if(x<=rem){
				val = x;
			}
		}
		if(val == -1){
			ans++;
			rem = w;
			continue;
		}
		rem -= val;
		int pos = f(val);
		bits[pos]--;
		if(bits[pos]==0)
			st.erase(val);
	}
	cout << ans << endl;
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