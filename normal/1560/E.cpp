
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
	cin >> s;
	const int n = s.size();
	string ans = "";
	set<char> vis;
	for(int i=n-1;i>=0;i--){
		if(vis.count(s[i]) == 0)
			ans += s[i];
		vis.insert(s[i]);
	}
	reverse(all(ans));
	vector<int> freq(26);
	for(char c:s){
		freq[c-'a']++;
	}
	for(int i=0;i<ans.size();i++){
		if(freq[ans[i]-'a']%(i+1)){
			cout << "-1\n";
			return;
		}else{
			freq[ans[i]-'a'] /= (i+1);
		}
	}
	vector<int> now(26);
	string res;
	for(int i=0;i<n;i++){
		now[s[i]-'a']++;
		if(now == freq){
			res = s.substr(0,i+1);// << " " << ans << "\n";
			break;
		}
	}
	string temp = res;
	string check = res;
	for(int i=0;i<ans.size();i++){
		char c = ans[i];
		string curr = "";
		for(char x:temp){
			if(x != c)
				curr += x;
		}
		check += curr;
		temp = curr;
	}
	if(check != s){
		cout << "-1\n";
	}else{
		cout << res << " " << ans << "\n";
	}
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