    /**********************************************
	    AUTHOR :- Rishav Kumar
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
		string s;
        int a,b;
        cin>>a>>b;
        cin>>s;
        int n=s.size();
        s=" "+s;
        int i;
        for(i=1;i<=n;i++){
            if(s[i]=='1')
                b--;
            if(s[i]=='0')
                a--;
        }
        if(a<0||b<0){
            cout<<-1<<endl;
            return;
        }
        int flag=0;
        for(i=1;i<=n;i++){
            if(i==n-i+1)
                continue;
            if(s[i]=='?'){
                if(s[n-i+1]=='1'){
                    s[i]='1';
                    b--;
                }
                if(s[n-i+1]=='0'){
                    s[i]='0';
                    a--;
                }
            }
            else{
                if(s[n-i+1]!='?'&&s[i]!=s[n-i+1]){
                    flag=1;
                    break;
                }
            }
        }
        if(flag){
            cout<<-1<<endl;
            return;
        }
        for(i=1;i<=n;i++){
            if(i==n-i+1)
                continue;
            if(s[i]=='?'&&s[n-i+1]=='?'){
                if(a>b){
                    a-=2;
                    s[i]='0';
                    s[n-i+1]='0';
                }
                else{
                    b-=2;
                    s[i]='1';
                    s[n-i+1]='1';
                }
            }
        }
        if(n%2){
            if(s[(n+1)/2]=='?'){
                if(a>0){
                    s[(n+1)/2]='0';
                    a--;
                }
                else{
                    s[(n+1)/2]='1';
                    b--;
                }
            }
        }
        if(a!=0||b!=0){
            cout<<-1<<endl;
        }
        else{
            cout<<s.substr(1)<<endl;
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