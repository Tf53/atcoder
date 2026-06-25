#include <iostream>
#include <vector>

using namespace std;
using ll = long long;

ll count(vector<ll> print, ll time){
  ll c = 0;
  for(int i=1; i< print.size(); i++){
    c += time / print[i];
  }
  return c;
}

ll check(vector<ll> print, ll k){
  ll left = 1;
  ll right = 1000000000;
  while(left<right){
    ll mid = (left + right) / 2;
    ll c = count(print,mid);
    if(k <= c){right = mid;}
    else{left = mid+1;}
  }
  return right;
}
int main(){
  ll n, k;
  cin >> n >> k;
  vector<ll> print(n+1);
  for(int i=1; i<=n; i++){cin >> print[i];}
  cout << check(print,k) << endl;
}