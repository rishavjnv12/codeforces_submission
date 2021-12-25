/***********************************************
    AUTHOR :- Rishav Kumar
    Created at: - 2021-03-18.10:33:50
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
#define MAX 100000001 // Checking cf
int spf[MAX];
void seive(){
    for(int i=1;i<MAX;i++){
        spf[i] = i;
    }
    for(int i=4;i<MAX;i+=2){
        spf[i] = 2;
    }
    for(int i=3;i*i<MAX;i+=2){
        for(int j=i*i;j<MAX;j+=i){
            if(spf[j]==j){
                spf[j] = i;
            }
        }
    }
}
int getf(int n){
    map<int,int> mp;
    while(n!=1){
        mp[spf[n]]++;
        n/=spf[n];
    }
	int ans = 1;
	for(auto pp:mp){
		if((pp.second)&1)
			ans *= pp.first;
	}
    return ans;
}
void solve(){
	int n,k;read(n,k);
	vi a(n);read(a);
	int ans = 1;
	set<int> st;
	st.insert(getf(a[0]));
	for(int i=1;i<n;i++){
		int extra = getf(a[i]);
		if(st.count(extra)){
			ans++;
			st.clear();
			st.insert(extra);
		}else{
			st.insert(extra);
		}
	}
	cout << ans << '\n';
	
}
int32_t main(){
	int t = 1;
	read(t);
	seive();
	for(int testcase = 0;testcase<t;testcase++){
			#ifdef F
					cout << testcase << ":";
			#endif
			solve();
	}
	return 0;
}