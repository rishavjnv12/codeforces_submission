/***********************************************
    AUTHOR :- Rishav Kumar
    Created at: - 2021-05-24.20:14:51
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
vector<int> tree;
int n;
void build(vector<int> &a,int v,int tl,int tr){
	if(tl == tr){
		tree[v] = a[tl];
	}else {
        int tm = (tl + tr) / 2;
        build(a, v*2, tl, tm);
        build(a, v*2+1, tm+1, tr);
        tree[v] = min(tree[v*2],tree[v*2+1]);
    }
}
int range_min(int v,int tl,int tr,int l,int r){
    if(l>r)
        return LLONG_MAX;
    if(l==tl and r==tr)
        return tree[v];
    int tm = (tl+tr)/2;
    int leftmin = range_min(2*v,tl,tm,l,min(r,tm));
    int rightmin = range_min(2*v+1,tm+1,tr,max(l,tm+1),r);
    return min(leftmin,rightmin);
}
bool check(int sz,vector<int> &a){
	int x = 0;
	for(int i=sz-1;i<n;i++,x++){
		int mindiff = range_min(1,0,n-2,x,i-1);
		// cout << sz << " " << mindiff << " " << a[i] << "\n";
		if(mindiff>=a[i])
			return true;
	}
	return false;
}
void solve(){
	read(n);
	vi a(n);read(a);
	if(n==1){
		cout << "1\n";
		return;
	}
	sort(all(a));
	int ans = 1;
	int l=1,r=n;
	vector<int> diff;
	for(int i=1;i<n;i++)
		diff.push_back(a[i]-a[i-1]);
	// debug() << imie(diff);
	tree.clear();
	tree.resize(4*n);
	build(diff,1,0,n-2);
	while(l<=r){
		int mid = (l+r)/2;
		if(check(mid,a)){
			ans = mid;
			l = mid+1;
		}else{
			r = mid-1;
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