/***********************************************
    AUTHOR :- Rishav Kumar
    Created at: - 2021-05-07.20:19:53
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
const int prime = 1e9+7;
const int prime2 = 1e9+9;
void solve(){
	int n;read(n);
	vi a(n);read(a);
	vector<vector<int>> ans;
	for(int i=1;i<n;i++){
		if(__gcd(a[i-1],a[i])!=1){
			int mn = min(a[i-1],a[i]);
			int pr;
			if(i-2>=0 and a[i-2]==prime){
				pr = prime2;
			}else{
				pr = prime;
			}
			a[i-1] = pr;
			a[i] = mn;
			ans.push_back({i,i+1,pr,mn});
		}
	}
	debug() << imie(a);
	assert(ans.size()<=n);
	for(int i=1;i<n;i++){
		assert(__gcd(a[i-1],a[i])==1);
	}
	cout << ans.size() << "\n";
	for(auto &v:ans)
		cout << v[0] << " " << v[1] << " " << v[2] << " " << v[3] << "\n";
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