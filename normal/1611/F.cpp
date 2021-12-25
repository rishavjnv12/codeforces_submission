/***********************************************
    AUTHOR :- Rishav Kumar
    Created at: - 2021-12-04.13:16:56
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
void build(vector<int> &a,int v,int left,int right){
    if(left==right)
        tree[v] = a[left];
    else{
        int mid = (left+right)/2;
        build(a,v*2,left,mid);
        build(a,v*2+1,mid+1,right);
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
void solve(){
	int n,s;read(n,s);
	vi a(n);read(a);
	partial_sum(all(a),a.begin());
	tree.clear();
	tree.resize(4*n);
	build(a,1,0,n-1);
	pair<int,int> global_ans = {-1,-1};
	int len = 0;
	debug() << imie(a);
	for(int i=0;i<n;i++){
		int l=1,r=n-i;
		while(l<=r){
			int m = (l+r)/2;
			int mn = range_min(1,0,n-1,i,i+m-1);
			// int mn = *min_element(a.begin()+i,a.begin()+i+m);
			if(i) mn -= a[i-1];
			bool ok = false;
			if(mn>=0 or abs(mn)<=s){
				ok = true;
				if(m>len){
					len = m;
					global_ans = {i,i+m-1};
				}
			}
			if(ok) l = m+1;
			else r = m-1;
		}
	}
	if(len == 0) cout << "-1\n";
	else cout << global_ans.first+1 << " " << global_ans.second+1 << "\n";
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