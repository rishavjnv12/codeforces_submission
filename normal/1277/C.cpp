/***********************************************
    AUTHOR :- Rishav Kumar
    Created at: - 2021-06-24.17:28:13
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
void solve(){
	string s;
	read(s);
	int n = s.length();
	s += "$$$$$$";
	set<int> st;
	for(int i=0;i<n;i++){
		if(s.substr(i,5) == "twone"){
			st.insert(i+2);
		}
	}
	vector<pair<char,int>> curr;
	for(int i=0;i<n;i++){
		if(st.count(i)==0){
			curr.push_back({s[i],i});
		}
	}
	n = curr.size();
	curr.push_back({'$',INT_MAX});
	curr.push_back({'$',INT_MAX});
	curr.push_back({'$',INT_MAX});
	curr.push_back({'$',INT_MAX});
	curr.push_back({'$',INT_MAX});
	curr.push_back({'$',INT_MAX});
	for(int i=0;i<n;i++){
		char a = curr[i].first;
		char b = curr[i+1].first;
		char c = curr[i+2].first;
		string temp({a,b,c});
		if(temp=="two" or temp == "one"){
			st.insert(curr[i+1].second);
		}
	}
	cout << st.size() << "\n";
	for(int x:st){
		cout << x+1 << " ";
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