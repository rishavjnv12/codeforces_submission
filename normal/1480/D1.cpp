#include <bits/stdc++.h>
using namespace std;

//Compiler version g++ 6.3.0

int main()
{
  int n;
  cin >> n;
  vector<int> a(n);
  for(int &x:a) cin >> x;
  vector<int> p({-1}),q({-1});
  for(int x:a){
     if(x==p.back()) q.push_back(x);
     else p.push_back(x);
  }
  int sg1 = unique(p.begin(),p.end())-p.begin();
  int sg2 = unique(q.begin(),q.end())-q.begin();
  cout << sg1+sg2-2 << endl;
    return 0;  
}