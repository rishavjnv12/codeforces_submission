/***********************************************
    AUTHOR :- Rishav Kumar
    Created at: - 2021-06-06.20:20:18
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
// Source :- https://www.geeksforgeeks.org/check-string-substring-another/
int isSubstring(string &s1, string &s2)
{
    int M = s1.length();
    int N = s2.length();
 
    /* A loop to slide pat[] one by one */
    for (int i = 0; i <= N - M; i++) {
        int j;
 
        /* For current index i, check for
 pattern match */
        for (j = 0; j < M; j++)
            if (s2[i + j] != s1[j])
                break;
 
        if (j == M)
            return i;
    }
 
    return -1;
}
void solve(){
	int n;cin >> n;
	string s;cin >> s;
	string ans = s + 'a';
	for(char c='a';c<='z';c++){
		bool found = false;
		for(int i=0;i<n;i++){
			if(s[i]==c){
				found = true;
				break;
			}		
		}
		if(found==false){
			cout << c << "\n";
			return;
		}
	}


	for(char c='a';c<='z';c++){
		for(char d='a';d<='z';d++){
			string mex = string(1,c)+string(1,d);
			bool found = false;
			for(int i=0;i<n-1;i++){
				if(s[i]==c and s[i+1]==d){
					found = true;
					break;
				}
			}
			if(found==false){
				cout << c << d << "\n";
				return;
			}
		}
	}
	for(char c='a';c<='z';c++){
		for(char d='a';d<='z';d++){
			for(char e='a';e<='z';e++){
			
				bool found = false;
				for(int i=0;i<n-2;i++){
					if(s[i]==c and s[i+1]==d and s[i+2]==e){
						found = true;
						break;
					}
				}
				if(found==false){
					cout << c << d << e << "\n";
					return;
				}
			}
		}
	}
	assert(false);
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