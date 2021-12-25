/***********************************************
    AUTHOR :- Rishav Kumar
    Created at: - 2021-05-07.20:50:30
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
int query(int t,int i,int j,int x){
	printf("? %lld %lld %lld %lld\n",t,i,j,x);
	fflush(stdout);
	int y;
	cin >> y;
	return y;
}
void solve(){
	int n;read(n);
	vi a(n+1);
	int nidx = -1;
	for(int i=2;i<=n;i++){
		int g = query(1,i-1,i,n-1);
		if(g == n){
			nidx = i;
			break;
		}
	}
	if(nidx == -1)
		nidx = 1;
	a[nidx] = n;
	for(int i=1;i<=n;i++){
		if(i==nidx){
			continue;
		}else{
			int g = query(2,i,nidx,1);
			a[i] = g;
		}
	}
	cout << "! ";
	for(int i=1;i<=n;i++){
		cout << a[i] << " ";
	}
	cout << endl;
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