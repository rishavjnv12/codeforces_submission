/***********************************************
    AUTHOR :- Rishav Kumar
    Created at: - 2021-09-30.13:02:19
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

int fun(vector<int> &a,int x){
	int lo = 0,hi = a.size()-1;
	int ans = -1;
	while(lo <= hi){
		int mid = (lo+hi)/2;
		if(a[mid]<=x){
			ans = mid;
			lo = mid+1;
		}else{
			hi = mid-1;
		}
	}
	return ans == -1?a[0]:a[ans];
}
int fun2(vector<int> &a,int x){
	int lo = 0,hi = a.size()-1;
	int ans = -1;
	while(lo <= hi){
		int mid = (lo+hi)/2;
		if(a[mid]>=x){
			ans = mid;
			hi = mid-1;
		}else{
			lo = mid+1;
		}
	}
	return ans == -1?a[0]:a[ans];
}
void solve(){
	int n;read(n);
	vi a(n);read(a);
	sort(all(a));
	int sum = 0;
	for(int x:a)
		sum += x;
	int q;read(q);
	while(q--){
		// cout << q << " ";
		int x,y;read(x,y);
		int hero = fun(a,x);
		int hero2 = fun2(a,x);
		int def = sum - hero;
		int def2 = sum - hero2;
		int ans = hero>=x?0:x-hero;
		int ans2 = hero2>=x?0:x-hero2;
		ans += (def>=y?0:y-def);
		ans2 += (def2>=y?0:y-def2);
		cout << min(ans,ans2) << "\n";
	}
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