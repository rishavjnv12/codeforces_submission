/***********************************************
    AUTHOR :- Rishav Kumar
    Created at: - 2021-03-18.21:02:46
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
template<typename T>T cd(T u,T v){return (u+v-1)/v;}
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()
#define vi vector<int>
/***********************************************************/
void solve(){
	int n;read(n);
	vi a(n);read(a);

	int mx_answer = LLONG_MAX;
	vi dp(n);
	int sm = 0;
	int mn;
	int c = 0;
	for(int i=0;i<n;i+=2){
		if(i==0){
			dp[i] = n*a[i];
			mn = a[i];
			sm += a[i];
			c = 1;
		}else{
			sm += a[i];
			mn = min(mn,a[i]);
			c++;
			debug() << imie(sm) imie(mn) imie(c);
			dp[i] = (sm-mn)+mn*(n-c+1);
		}
	}
	sm = 0;
	c = 0;
	for(int i=1;i<n;i+=2){
		if(i==1){
			dp[i] = n*a[i];
			mn = a[i];
			sm += a[i];
			c = 1;
		}else{
			sm += a[i];
			mn = min(mn,a[i]);
			c++;
			debug() << imie(sm) imie(mn) imie(c);
			dp[i] = (sm-mn)+mn*(n-c+1);
		}
	}
	debug() << imie(dp);

	for(int i=1;i<n;i++)
		mx_answer = min(mx_answer,dp[i]+dp[i-1]);
	
	cout << mx_answer << "\n";
	// vi f,s;
	// for(int i=0;i<n;i++){
	// 	if(i&1) s.push_back(a[i]);
	// 	else f.push_back(a[i]);
	// }
	// sort(rall(f));
	// sort(rall(s));
	// int ans = 0;
	// for(int i=0;i<(int)f.size();i++){
	// 	if(i==f.size()-1){
	// 		ans += ((n-i)*f[i]);
	// 	}else{
	// 		ans += f[i];
	// 	}
	// }
	
	// for(int i=0;i<(int)s.size();i++){
	// 	if(i==s.size()-1){
	// 		ans += ((n-i)*s[i]);
	// 	}else{
	// 		ans += f[i];
	// 	}
	// }
	// cout << ans << "\n";
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