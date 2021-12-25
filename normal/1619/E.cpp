/***********************************************
    AUTHOR :- Rishav Kumar
    Created at: - 2021-12-20.20:32:30
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
	int n;read(n);
	vi a(n);read(a);
	sort(all(a));
	vector<int> mp(n+1);
	for(int x:a) mp[x]++;
	vector<int> pref(n+1);
	partial_sum(all(mp),pref.begin());
	auto temp = mp;
	vector<int> ops(n+1);
	set<int> st;
	if(mp[0] == 0){
		cout << "0 ";
		for(int i=1;i<=n;i++) cout << "-1 ";
		cout << "\n";
		return;
	}
	if(mp[0] > 1){
		st.insert(0);
	}
	
	for(int i=1;i<=n;i++){
		if(ops[i-1] == -1) {
			ops[i] = -1;
			continue;
		}
		if(temp[i] == 1) ops[i] = ops[i-1];
		else if(temp[i] > 1){
			ops[i] = ops[i-1];
			st.insert(i);
		} else {
			if(st.empty()){
				ops[i] = -1;
				continue;
			}
			int ele = *st.rbegin();
			ops[i] = ops[i-1] + (i-ele);
			temp[ele]--;
			if(temp[ele] == 1){
				st.erase(ele);
			}
		}
	}
	debug() << imie(ops);
	for(int i=0;i<=n;i++){
		if(i == 0){
			if(mp[i] == 0){
				cout << "0 ";
			}else{
				cout << mp[0] << " ";
			}
		}else{
			if(ops[i-1] == -1){
				cout << "-1 ";
			}else{
				cout << mp[i]+ops[i-1] << " ";
			}
		}
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