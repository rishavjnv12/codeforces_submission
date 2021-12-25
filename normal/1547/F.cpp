/***********************************************
    AUTHOR :- Rishav Kumar
    Created at: - 2021-07-11.17:57:12
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
template<typename T>T cd(T u,T v){return (u+v-1)/2;}
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()
#define vi vector<int>
/***********************************************************/
vector<int> tree;
void build(int v,int tl,int tr,vector<int> &a){
	if(tl == tr){
		tree[v] = a[tl];
	}else{
		int tm = (tl+tr)/2;
		build(2*v,tl,tm,a);
		build(2*v+1,tm+1,tr,a);
		tree[v] = __gcd(tree[2*v],tree[2*v+1]);
	}
}
int gcd(int v, int tl, int tr, int l, int r) {
    if (l > r) 
        return 0;
    if (l == tl && r == tr) {
        return tree[v];
    }
    int tm = (tl + tr) / 2;
    return __gcd(gcd(v*2, tl, tm, l, min(r, tm)),gcd(v*2+1, tm+1, tr, max(l, tm+1), r));
}

void solve(){
	int n;read(n);
	vi a(n);read(a);
	for(int i=0;i<n;i++)
		a.push_back(a[i]);
	int g = 0;
	for(int x:a){
		g = __gcd(g,x);
	}
	for(int &x:a){
		x /= g;
	}
	if(set<int>(all(a)).size()==1){
		cout << "0\n";
		return;
	}
	// tree.clear();
	tree.resize(8*n);
	build(1,0,2*n-1,a);
	int ans = -1;
	int l = 0,r = n-1;
	function<int(int,int)> brut = [&](int l,int r){
		int ans = 0;
		for(int i=l;i<=r;i++)
			ans = __gcd(ans,a[i]);
		return ans;
	};
	function<bool(int)> check = [&](int k){
		int left = 0,right = left+k-1;
		while(right<2*n){
			int g = gcd(1,0,2*n-1,left,right);
			left++;
			right++;
			if(g != 1)
				return true;
		}
		return false;
	};
	while(l<=r){
		int mid = (l+r)/2;
		if(check(mid)){
			ans = mid;
			l = mid+1;
		}else{
			r = mid-1;
		}
	}
	cout << ans << "\n";
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