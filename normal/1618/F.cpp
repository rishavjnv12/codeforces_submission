/***********************************************
    AUTHOR :- Rishav Kumar
    Created at: - 2021-12-14.21:20:52
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
string to_bin(int x){
	string a = bitset<100>(x).to_string();
	reverse(all(a));
	while(a.size() and a.back() == '0')
		a.pop_back();
	reverse(all(a));
	return a;
}
set<string> st;

void dfs(string s){
	if(s.size() >= 63)
		return;
	auto temp1 = s+'1';
	auto temp2 = s+'0';
	while(temp2.size() and temp2.back() == '0') temp2.pop_back();
	reverse(all(temp1));
	reverse(all(temp2));
	if(st.count(temp1) == 0){
		st.insert(temp1);
		dfs(temp1);
	}
	if(st.count(temp2) == 0){
		st.insert(temp2);
		dfs(temp2);
	}
}


void solve(){
	int x,y;read(x,y);
	string a = to_bin(x),b = to_bin(y);
	st.insert(a);
	dfs(a);
	cout << (st.count(b)?"YES":"NO") << "\n";
}



int32_t main(){
	ios_base::
	sync_with_stdio(false);
    cin.tie(NULL);
	int t = 1;
	// read(t);
	for(int testcase = 1;testcase<=t;testcase++){
			#ifdef GOOGLE
				cout << "Case #" << testcase << ": ";
			#endif
			solve();
	}
	return 0;
}