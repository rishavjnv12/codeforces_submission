/***********************************************
    AUTHOR :- Rishav Kumar
    Created at: - 2021-04-03.20:15:16
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
bool check(string &s,string &t,int i,int j){
	for(int x=i;x<=j;x++){
		if(s[x]!=t[x])
			return false;
	}
	return true;
}
bool check2(string &s,string &t,int i,int j){
	bool flag = true;
	for(int x=i;x<=j;x++){
		if(s[x]==t[x])
			return false;
	}
	return true;
}
void solve(){
	int n;read(n);
	string a,b;read(a);read(b);
	while(a.size() and a.back()==b.back()){
		a.pop_back();
		b.pop_back();
	}
	if(a==b){
		cout << "YES\n";
		return;
	}
	vector<int> pos(1,0);
	int o=0,z=0;
	int bo=0,bz=0;
	for(int i=0;i<(int)a.size();i++){
		if(a[i]=='1') o++;
		else z++;
		if(o==z) pos.push_back(i);
		if(b[i]=='1') bo++;
		else bz++;
	}
	debug() << imie(pos);
	// cout << o << " " << z << endl;
	if(o!=z){
		cout << "NO\n";
		return;
	}
	if(o==bo and z==bz){
		cout << "YES\n";
		return;
	}else{
		cout << "NO\n";
		return;
	}
	
	for(int i=1;i<pos.size();i++){
		if(check(a,b,pos[i-1]+1,pos[i]) or check2(a,b,pos[i-1]+1,pos[i])){
			//fine
		}else{
			cout << "NO\n";
			return;
		}
	}
	cout << "YES\n";
	
}
bool c(string &a,string &b){
	if(a==b)
		return true;
	for(char &c:a){
		if(c=='0') c='1';
		else c='0';
	}
	return a==b;
}
void solve2(){
	int n;read(n);
	string a,b;read(a);read(b);
	int o=0,z=0;
	while(a.size() and a.back()==b.back()){
		a.pop_back();
		b.pop_back();
	}
	if(a.empty()){
		cout << "YES\n";
		return;
	}
	string x="",y="";
	vector<pair<string,string>> v;
	for(int i=0;i<(int)a.size();i++){
		if(a[i]=='1') o++;
		else z++;
		x += a[i];
		y += b[i];
		if(o==z){
			v.push_back({x,y});
			x = "";
			y = "";
		}
	}
	if(o!=z){
		cout << "NO\n";
		return;
	}
	debug() << imie(v);
	for(auto &p:v){
		if(c(p.first,p.second)==false){
			cout << "NO\n";
			return;
		}
	}
	cout << "YES\n";
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
			solve2();
	}
	return 0;
}