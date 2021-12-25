/***********************************************
    AUTHOR :- Rishav Kumar
    Created at: - 2021-03-18.20:32:27
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
	string s;read(s);
	int n = s.size();
	if(is_sorted(all(s))){
		puts("YES");
		return;
	}
	// int i = 0,j = n-1;
	// while(i<n and s[i]=='0') i++;
	// while(j>=0 and s[j]=='1') j--;
	// vi o,z;
	// for(int k=i;k<=j;k++){
	// 	if(s[k]=='0') z.push_back(k);
	// 	else o.push_back(k);
	// }
	bool o = true;
	vi seq;
	bool ans = true;
	for(int i=n-1;i>=0;i--){
		if(o){
			if(s[i]=='1') continue;
			else if(seq.empty())
				seq.push_back(i);
			else if(seq.back()>i+1)
				seq.push_back(i);
			else o = false;
		}else{
			if(s[i]=='0') continue;
			else if(seq.empty())
				seq.push_back(i);
			else if(seq.back()>i+1)
				seq.push_back(i);
			else ans = false;
		}
	}
	if(ans) puts("YES");
	else puts("NO");
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