/***********************************************
    AUTHOR :- Rishav Kumar
    Created at: - 2021-03-29.23:59:35
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
#define MAX 1000005
using namespace std;
bool prime[MAX+1];
void seive(){
    memset(prime,true,sizeof(prime));
	prime[1] = true;
    for(int i=2;i*i<=MAX;i++){
        if(prime[i]){
            for(int j=i*i;j<=MAX;j+=i){
                prime[j]=false;
            }
        }
    }
}
void solve(){
	int x;read(x);
	int y = sqrt(x);
	if(y!=1 and y*y==x and prime[y]==true){
		puts("YES");
	}else{
		puts("NO");
	}
}
int32_t main(){
	ios_base::
	sync_with_stdio(false);
    cin.tie(NULL);
	int t = 1;
	seive();
	read(t);
	for(int testcase = 1;testcase<=t;testcase++){
			#ifdef F
					cout << testcase << ":";
			#endif
			solve();
	}
	return 0;
}