/***********************************************
    AUTHOR :- Rishav Kumar
    Created at: - 2021-04-07.20:46:06
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
const int mod = 1e9+7;
int ans;
int add(long long a,long long b){
    return a+b;
}
void merge(vector<int> &v,int l,int mid,int r){
    int m = mid-l+1;
    int n = r-mid;
    int left[m],right[n];
    for(int i=0;i<m;i++){
        left[i] = v[i+l];
    }
    for(int i=0;i<n;i++){
        right[i] = v[mid+1+i];
    }
    int i=0,j=0,x=l;
    while(i<m and j<n){
        if(left[i]<=right[j]){
            v[x] = left[i];
            i++;
        }else{
            ans = add(ans,(mid-(i+l)+1));
            v[x] = right[j];
            j++;
        }
        x++;
    }
    while(i<m){
        v[x] = left[i];
        x++;
        i++;
    }
    while(j<n){
        v[x] = right[j];
        j++;
        x++;
    }
}

void merge_sort(vector<int> &v,int l,int r){
    if(l<r){
        int m = l+(r-l)/2;
        merge_sort(v,l,m);
        merge_sort(v,m+1,r);
        merge(v,l,m,r);
    }
}
void solve(){
	int n;read(n);
	string s;
	read(s);
	vector<vector<int>> idx(26);
	vector<int> ptr(26);
	for(int i=0;i<n;i++){
		idx[s[i]-'a'].push_back(i);
	}
	vector<int> f(n);
	reverse(all(s));
	for(int i=0;i<n;i++){
		int c = s[i]-'a';
		f[i] = idx[c][ptr[c]];
		ptr[c]++;
	}
	merge_sort(f,0,n-1);
	cout << ans << endl;

}
int32_t main(){
	ios_base::
	sync_with_stdio(false);
    cin.tie(NULL);
	int t = 1;
	// read(t);
	for(int testcase = 1;testcase<=t;testcase++){
			#ifdef F
					cout << testcase << ":";
			#endif
			solve();
	}
	return 0;
}