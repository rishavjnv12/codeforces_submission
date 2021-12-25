/***********************************************
    AUTHOR :- Rishav Kumar
    Created at: - 2021-04-29.20:27:43
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
int fun(int n,int k){
	return n-n%k;
}
void solve(){
	int n;read(n);
	vi u(n),s(n);
	read(u);read(s);
	vector<vector<int>> enroll(n+1);
	for(int i=0;i<n;i++)
		enroll[u[i]].push_back(s[i]);
	vector<vector<int>> ff;
	for(auto &v:enroll)
		if(v.size())
			ff.emplace_back(v);
	int mx_sz = 0;
	for(auto &v:ff){
		sort(rall(v));
		partial_sum(all(v),v.begin());
		mx_sz = max(mx_sz,(int)v.size());
	}
	sort(ff.begin(),ff.end(),[&](auto &a,auto &b){
		return a.size() < b.size();
	});
	vi ans;
	for(int k=1;k<=mx_sz;k++){
		int curr = 0;
		for(auto &v:ff){
			int sz = v.size();
			int upto = fun(sz,k);
			if(sz+1<k){
				debug() << imie(curr);
				break;
			}
			if(upto == 0)
				continue;
			else
				curr += v[upto-1];
		}
		ans.push_back(curr);
	}
	for(int k=mx_sz+1;k<=n;k++) ans.push_back(0);
	// assert(ans.size() == n);
	for(int x:ans)
		cout << x << " ";
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