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
template<typename T>void read(vector<T>& a){for(T& x:a)cin >> x;}
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()
#define vi vector<int>
/***********************************************************/
void solve(){
	int n;read(n);
	vi a(n);read(a);
	int mx = 2*(*max_element(all(a)));
	map<int,int> mp;
	for(int x:a) {
		mp[x]++;
		if(mp[x]==4){
			vi ans;
			for(int i=0;i<n and ans.size()<4;i++){
				if(a[i]==x)
						ans.push_back(i+1);
			}
			puts("YES");
			for(int y:ans){
				cout << y << " "; 
			}
			cout << "\n";
			return;
		}
	}

    vector<pair<int,int>> b(mx,{-1,-1});
    for (int i=0;i<n;i++) {
        for (int j = 0; j < i; j++) {
            int x=a[i]+a[j];
            if (b[x].first==b[x].second) {
                b[x] = {i, j};
            } else if (set<int>({b[x].first, b[x].second, i, j}).size() == 4) {
                puts("YES");
                cout << b[x].first + 1 << " " << b[x].second + 1<< " " << i + 1 << " " << j + 1 << "\n";
                return;
            }
        }
    }
    assert(n<=1000);
    std::cout << "NO\n";

}
int32_t main(){
	int t = 1;
	// read(t);
	for(int testcase = 0;testcase<t;testcase++){
			#ifdef F
					cout << testcase << ":";
			#endif
			solve();
	}
	return 0;
}