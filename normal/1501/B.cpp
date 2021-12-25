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
template<typename T>void read(vector<T>& a){for(T& x:a)cin >> x;}
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()
#define vi vector<int>
/***********************************************************/
vector<vector<int>> merge(vector<vector<int>>& i) {
	sort(i.begin(),i.end());
	auto it = unique(i.begin(),i.end(),[](vector<int> &a,vector<int> &b){
		if(a[1]>=b[0]){
			a[1]=max(a[1],b[1]);
			return true;
		}
		return false;
	});
	i.resize(it-i.begin());
	return i;
}
void solve(){
	int n;
	read(n);
	vi a(n);read(a);
	int l = 0,r = 0;
	vector<vector<int>> v;
	for(int i=0;i<n;i++){
		if(a[i])
			v.push_back({max(0LL,i-a[i]+1),i});
	}
	v = merge(v);
	vector<int> ans(n);
	for(auto &p:v){
		for(int i=p[0];i<=p[1];i++)
			ans[i] = 1;
	}
	for(int x:ans)
		cout << x << " ";
	cout << "\n";
	debug() << imie(v);
}
int32_t main(){
	int t = 1;
	read(t);
	for(int testcase = 0;testcase<t;testcase++){
			#ifdef F
					cout << testcase << ":";
			#endif
			solve();
	}
	return 0;
}