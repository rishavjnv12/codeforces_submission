/***********************************************
    AUTHOR :- Rishav Kumar
    Created at: - 2021-12-22.11:58:13
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
	int n,m,k;
	cin >> n >> m >> k;
	vector<int> tables(m);
	for(int i=0;i<m;i++) tables[i] = n/m;
	int rem = n%m;
	for(int i=m-1,x=0;x<rem;i--,x++) tables[i]++;
	int here = *min_element(all(tables));
	set<pair<int,int>> pq;
	for(int i=1;i<=n;i++) pq.insert({0,i});
	for(int game = 0; game < k;game++){
		set<pair<int,int>> curr;
		int x = 1;
		for(int z=0;z<m;z++){
			cout << tables[z] << " ";
			for(int i=0;i<tables[z];i++){
				if(tables[z] == here){
					assert(pq.size());
					pair<int,int> big = *pq.rbegin();
					cout << big.second << ' ';
					curr.insert(big);
					pq.erase(big);
				}else{
					assert(pq.size());
					pair<int,int> small = *pq.begin();
					cout << small.second << " ";
					curr.insert({small.first+1,small.second});
					pq.erase(small);
				}
				
			}
			cout << "\n";
			
		}
		pq = curr;
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