/***********************************************
    AUTHOR :- Rishav Kumar
    Created at: - 2021-10-24.16:26:03
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
int lcm(int a,int b){
	return (a/__gcd(a,b))*b;
}
void solve(){
	int n;read(n);
	vi a(n);read(a);
	int l = 1;
	for(int x:a){
		l = lcm(l,x);
	}
	int mn = 0;
	int midx = -1;
	for(int i=0;i<n;i++){
		if(abs(a[i])>mn){
			mn = abs(a[i]);
			midx = i;
		}
	}
	vector<int> b(n);
	vector<pair<int,int>> v;
	for(int i=0;i<n;i++)
		v.push_back({a[i],i});
	sort(all(v),[&](auto a,auto b){
		return abs(a.first)<abs(b.first);
	});

	int move = 1;
	for(int i=0;i<n;i++){
		int idx = v[i].second;
		int x = a[idx];
		if(idx == midx){
			// b[i] = l/a[i];
			// do nothing
		}else{
			if(move)
				b[idx] = -1 * (l/x);
			else 
				b[idx] = 1 * (l/x);
			
			move ^= 1;
		}
	}
	int check = 0;
	for(int i=0;i<n;i++){
		if(i != midx)
			check += (a[i]*b[i]);
	}
	
	if(check == 0){
		for(int i=0;i<2;i++){
			if(i!=midx){
				b[i] *= -1;
				break;
			}
		}
	}
	b[midx] = -1*(check/a[midx]);
	check = 0;
	for(int i=0;i<n;i++){
		if(i != midx)
			check += (a[i]*b[i]);
	}
	// cout << check << "\n";
	b[midx] = -1*check/a[midx];

	int cc = 0;
	for(int i=0;i<n;i++){
		cc += (a[i]*b[i]);
	}
	assert(cc == 0);
	for(int x:b){
		cout << x << " ";
	}
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