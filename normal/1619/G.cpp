/***********************************************
    AUTHOR :- Rishav Kumar
    Created at: - 2021-12-22.19:45:49
***********************************************/
#include <bits/stdc++.h>
// #define int long long
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
void read(){}
template <typename T, typename... Types>
void read(T &var1, Types&... var2){cin >> var1;read(var2...);}
template<typename T>void read(vector<T>& a){for(T& x:a)read(x);}
template<typename T>T cd(T u,T v){return (u+v-1)/v;}
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()
#define vi vector<int>
/***********************************************************/
struct dsu {
  public:
    dsu() : _n(0) {}
    explicit dsu(int n) : _n(n), parent_or_size(n, -1) {}

    int merge(int a, int b) {
        assert(0 <= a && a < _n);
        assert(0 <= b && b < _n);
        int x = leader(a), y = leader(b);
        if (x == y) return x;
        if (-parent_or_size[x] < -parent_or_size[y]) std::swap(x, y);
        parent_or_size[x] += parent_or_size[y];
        parent_or_size[y] = x;
        return x;
    }

    bool same(int a, int b) {
        assert(0 <= a && a < _n);
        assert(0 <= b && b < _n);
        return leader(a) == leader(b);
    }

    int leader(int a) {
        assert(0 <= a && a < _n);
        if (parent_or_size[a] < 0) return a;
        return parent_or_size[a] = leader(parent_or_size[a]);
    }

    int size(int a) {
        assert(0 <= a && a < _n);
        return -parent_or_size[leader(a)];
    }

    std::vector<std::vector<int>> groups() {
        std::vector<int> leader_buf(_n), group_size(_n);
        for (int i = 0; i < _n; i++) {
            leader_buf[i] = leader(i);
            group_size[leader_buf[i]]++;
        }
        std::vector<std::vector<int>> result(_n);
        for (int i = 0; i < _n; i++) {
            result[i].reserve(group_size[i]);
        }
        for (int i = 0; i < _n; i++) {
            result[leader_buf[i]].push_back(i);
        }
        result.erase(
            std::remove_if(result.begin(), result.end(),
                           [&](const std::vector<int>& v) { return v.empty(); }),
            result.end());
        return result;
    }

  private:
    int _n;
    // root node: -1 * component size
    // otherwise: parent
    std::vector<int> parent_or_size;
};



void solve(){
	int n,k;read(n,k);
	vector<vector<int>> mines(n,vector<int>(3));
	read(mines);
	for(int i=0;i<n;i++) mines[i].push_back(i);
	dsu ds(n);
	map<int,vector<pair<int,int>>> x_to_y,y_to_x; // x-> y,index
	for(auto &v:mines){
		x_to_y[v[0]].push_back({v[1],v[3]});
		y_to_x[v[1]].push_back({v[0],v[3]});
	}
	for(auto &[_,v]:x_to_y) sort(all(v));
	for(auto &[_,v]:y_to_x) sort(all(v));
	debug() << imie(x_to_y);
	debug() << imie(y_to_x);
	for(auto &[_,v]:x_to_y){
		int sz = v.size();
		for(int i=1;i<sz;i++){
			if(abs(v[i].first - v[i-1].first) <= k)
				ds.merge(v[i].second,v[i-1].second);
		}
	}
	
	for(auto &[_,v]:y_to_x){
		int sz = v.size();
		for(int i=1;i<sz;i++){
			if(abs(v[i].first - v[i-1].first) <= k)
				ds.merge(v[i].second,v[i-1].second);
		}
	}
	// TODO:- TLE, easy to optimise, focus on main algo
	// for(int i=0;i<n;i++){
	// 	int x1 = mines[i][0],y1 = mines[i][1];
	// 	for(int j=0;j<n;j++){
	// 		int x2 = mines[j][0],y2 = mines[j][1];
	// 		if(((x1 == x2) and abs(y1-y2)<=k) or ((y1 == y2) and abs(x1-x2)<=k))
	// 			ds.merge(i,j);  
	// 	}
	// }
	int l = 0,r = 1e9;
	function<bool(int)> check = [&](int m) -> bool{
		set<int> done;
		for(int i=0;i<n;i++){
			if(mines[i][2] <= m)
				done.insert(ds.leader(i));
		}
		int rem = 0;
		for(int i=0;i<n;i++){
			if(mines[i][2] > m and done.count(ds.leader(i)) == 0){
				rem++;
				done.insert(ds.leader(i));
			}
		}
		return rem <= (m+1);
	};
	int ans = -1;
	while(l<=r){
		int mid = (l+r)/2;
		if(check(mid)){
			ans = mid;
			r = mid-1;
		}else{
			l = mid+1;
		}
	}
	cout << ans << "\n";
	debug() << imie(mines);
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