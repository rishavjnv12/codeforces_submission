/***********************************************
    AUTHOR :- Rishav Kumar
    Created at: - 2021-12-19.11:11:53
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
	int l = 1,r = 1e9;
	int ans = -1;
	function<bool(int)> check = [&](int coin){
		for(int i=0;i<4;i++){
			for(int j=0;j<4;j++){
				bool ok = true;
				for(int cost:a){
					int k = coin - (i+j);
					bool here = false;
					for(int x=0;x<=i;x++){
						for(int y=0;y<=j;y++){
							int rem = cost - 1*x - 2*y;
							if(rem >= 0 and rem % 3 == 0 and rem / 3 <= k){
								here = true;
							}
						}
					}
					if(!here){
						ok = false;
						break;
					}
				}	
				if(ok)
					return true;
			}
		}
		return false;
	};
	while(l<=r){
		int m = (l+r)/2;
		if(check(m)){
			ans = m;
			r = m-1;
		}else{
			l = m+1;
		}
	}
	cout << ans << "\n";
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