/***********************************************
    AUTHOR :- Rishav Kumar
    Created at: - 2021-12-12.21:32:07
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
	auto v = a;
	sort(all(v));
	if(n<=2){
		cout << (a==v?"YES\n":"NO\n");
		return;
	}
	map<int,set<int>> mp;
	for(int i=0;i<n;i++) mp[a[i]].insert(i);
	for(int i=0;i<n-2;i++){
		if(a[i] == v[i]){
			mp[a[i]].erase(i);
		}else{
			int j = *mp[v[i]].begin();
			int k = (j==n-1)?n-2:n-1;
			mp[a[i]].erase(i);
			mp[a[k]].erase(k);
			mp[a[j]].erase(j);
			int temp = a[i];
			a[i] = a[j];
			a[j] = a[k];
			a[k] = temp;
			mp[a[k]].insert(k);
			mp[a[j]].insert(j);
			assert(set<int>({i,j,k}).size() == 3);
		}
		debug() << imie(mp);
	}
	// assert(is_sorted(a.begin(),a.begin()+n-2));
	// int mx = 0;
	// for(int i=0;i<n-2;i++) mx = max(mx,a[i]);
	// if(mx > min(a[n-1],a[n-2])){
	// 	cout << "NO\n";
	// 	return;
	// }
	for(int i=n-2;i<n;i++){
		if(a[i] != v[i]){
			map<int,int> mpp;
			for(int j=0;j<n;j++) mpp[a[j]]++;
			for(auto &p:mpp){
				if(p.second >= 2){
					cout << "YES\n";
					return;
				}
			}
			cout << "NO\n";
			return;
		}
	}
	assert(is_sorted(all(a)));
	cout << "YES\n";
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