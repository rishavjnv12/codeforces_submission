/***********************************************
    AUTHOR :- Rishav Kumar
    Created at: - 2021-05-05.21:07:07
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
int k = 0;
int query(int l,int r){
	k++;
	assert(k<=20);
	printf("? %lld %lld\n",l,r);
	fflush(stdout);
	int x;
	cin >> x;
	return x;
}
void solve(){
	int n,t;read(n,t);
	int k;read(k);
	int l = 1,r = n;
	while(l<=r){
		int mid = (l+r)/2;
		int curr = query(1,mid);
		if(mid-curr == k){
			printf("! %lld\n",mid);
			fflush(stdout);
			return;
		}else if(mid-curr > k){
			r = mid-1;
		}else{
			l = mid+1;
		}
	}
	assert(false);
}
int32_t main(){

	int t = 1;
	// read(t);
	
	for(int testcase = 1;testcase<=t;testcase++){
			#ifdef GOOGLE
				cout << "Case #" << testcase << ": ";
			#endif
			solve();
	}
	assert(k<=20);
	return 0;
}