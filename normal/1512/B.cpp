/*        AUTHOR :- Rishav Kumar
        Created at: - 2021-04-10.20:22:05
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
    	int a,b;read(a,b);
    	string s;read(s);
    	int n = s.size();
    	if((a+b)!=n){
    		// cout << "Here" << " ";
    		cout << "-1\n";
    		return;
    	}
    	for(char c:s)
    		if(c=='0') a--;
    		else if(c=='1') b--;
     
    	int i=0,j=n-1;
    	// cout << a << " " << b << "\n";
    	while(i<j){
    		if(s[i]!=s[j] and s[i]!='?' and s[j]!='?'){
    			cout << "-1\n";
    			return;
    		}
    		if(s[i]==s[j]){
    			if(s[i]=='?'){
    				if(a>b){
    					s[i] = s[j] = '0';
    					a-=2;
    				}else{
    					s[i] = s[j] = '1';
    					b-=2;
    					// cout << s << " ";
    				}
    			}
    		}else{
    			if(s[i]!='?'){
    				s[j] = s[i];
    				if(s[j] == '0') a--;
    				else b--;
    			}else{
    				s[i] = s[j];
    				if(s[j] == '0') a--;
    				else b--;
    			}
    		}
    		i++;
    		j--;
    	}
    	if(n&1 and s[i]=='?'){
    		if(a%2==0 and b%2==0){
				cout << "-1\n";
				return;
			}else if(a==1){
				s[n/2] = '0';
			}else if(b==1){
				s[n/2] = '1';
			}else{
				cout << "-1\n";
			}
    	}
    	if(!a and !b){
    		cout << s << "\n";
    		
    	}else{
    		cout << "-1\n";
    	}
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