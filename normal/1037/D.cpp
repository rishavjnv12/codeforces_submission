/***********************************************
    AUTHOR :- Rishav Kumar
    Created at: - 2021-06-02.20:19:02
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
bool fun(vector<int> &s,vector<int> &t){
	s.resize(unique(all(s))-s.begin());
	// return true if s is a subsequence of t, or false otherwise
	int i=0,j=0;
	int m = s.size(),n=t.size();
	while(i<m and j<n){
		if(s[i]==t[j]){
			i++;
			j++;
		}else{
			j++;
		}
	}
	if(i == m)
		return true;
	return false;
}
void solve(){
	int n;read(n);
	vector<vi> g(n+1);
	for(int i=1;i<n;i++){
		int x,y;read(x,y);
		g[x].push_back(y);
		g[y].push_back(x);
	}
	vi trav(n);read(trav);
	vector<int> order(n+1);
	for(int i=0;i<n;i++)
		order[trav[i]] = i;
	for(auto &v:g){
		sort(all(v),[&](int x,int y){
			return order[x] < order[y];
		}); 
	}
	vi vis(n+1,false);
	queue<int> q;
	q.push(1);
	vis[1] = true;
	vi mybfs;
	while(q.size()){
		int sz = q.size();
		while(sz--){
			int x = q.front();
			q.pop();
			mybfs.push_back(x);
			for(int c:g[x]){
				if(!vis[c]){
					vis[c] = 1;
					q.push(c);
				}
			}
		}
	}
	if(mybfs == trav){
		cout << "Yes\n";
	}else{
		cout << "No\n";
	}
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