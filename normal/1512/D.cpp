/***********************************************
    AUTHOR :- Rishav Kumar
    Created at: - 2021-04-10.20:55:14
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
	int n;read(n);
    vector<int> a(n+2);read(a);
    int s = 0;
    for(int x:a) 
        s += x;
    map<int,int> mp;
    for(int x:a)
        mp[x]++;
    // debug() << imie(mp);
    int x_found = -1,n_1 = -1;
    if(s&1){
        for(int i=0;i<n;i++){
            if(a[i]&1){
                debug() << imie(a[i]);
                int target = (s-a[i])/2;
                if(a[i]==target){
                    if(mp.count(target) and mp[target]>=2){
                        x_found = target;
                        n_1 = target;
                        break;
                    }
                }else{
                    if(mp.count(target)){
                        x_found = a[i];
                        n_1 = target;
                        break;
                    }
                }

            }
        }
    }else{
        for(int i=0;i<n;i++){
            if((a[i]&1)==0){
                // debug() << imie(a[i]);
                int target = (s-a[i])/2;
                debug() << imie(s) imie(a[i]) imie(target);
                if(a[i]==target){
                    if(mp.count(target) and mp[target]>=2){
                        x_found = target;
                        n_1 = target;
                        break;
                    }
                }else{
                    if(mp.count(target)){
                        x_found = a[i];
                        n_1 = target;
                        break;
                    }
                }

            }
        }
    }
    debug() << imie(x_found) imie(n_1);
    int ss = 0;
    
    if(x_found == -1){
        cout << "-1\n";
        return;
    }
    vector<int> ans;
    
    for(auto &p:mp){
        if(x_found == n_1){
            if(p.first == x_found){
                for(int i=0;i<p.second-2;i++)
                    ans.push_back(p.first);
            }else{
                for(int i=0;i<p.second;i++)
                    ans.push_back(p.first);
            }
        }else{
            if(p.first == n_1 or p.first==x_found){
                for(int i=0;i<p.second-1;i++)
                    ans.push_back(p.first);
            }else{
                for(int i=0;i<p.second;i++)
                    ans.push_back(p.first);
            }
        }
    }
    for(int x:ans)
        ss += x;
    assert(ss==n_1 and ans.size()==n);
    for(int x:ans)
        cout << x << " ";
    cout << "\n";
}
int32_t main(){
	ios_base::
	sync_with_stdio(false);
    cin.tie(NULL);
	int t = 1;
	read(t);
	for(int testcase = 1;testcase<=t;testcase++){
			#ifdef F
					cout << testcase << ":";
			#endif
			solve();
	}
	return 0;
}