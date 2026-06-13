#include <bits/stdc++.h>
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define rep3(i,m,n) for(int i=(int)(m);i<(int)(n);i++)
#define all(v) v.begin(), v.end()
using ll = long long;

using namespace std;

template <typename T>
int binary_search_target(const vector<T>& a, T target){
  int left=0, right=(int)a.size()-1;
  while(left<=right){
    int mid=(right+left)/2;
    if(a[mid]==target){return mid;}
    if(a[mid]<target){left=mid+1;}
    else{right=mid-1;}
  }
  return -1;
}

template <typename T>
int binary_search_higher(const vector<T>& a, T target){
  int ok=(int)a.size();
  int ng=-1;
  while(abs(ok-ng)>1){
    int mid=ng+(ok-ng)/2;
    if(a[mid]>=target) ok=mid;
    else ng=mid;
  }
  return ok;
}

template <typename T>
int binary_search_less(const vector<T>& a, T target){
  int ok=-1;
  int ng=(int)a.size();
  while(abs(ng-ok)>1){
    int mid=ok+(ng-ok)/2;
    if(a[mid]<=target) ok=mid;
    else ng=mid;
  }
  return ok;
}

ll nCr(ll n, ll r) {
    if(r<0||r>n)return 0;
    if(r>n-r)r=n-r;

    ll ans=1;
    for(ll i=1;i<=r;i++){
    ans*=(n-i+1);
    ans/=i;
  }
    return ans;
}

// sort(ans.begin(),ans.end(),[](const vector<int>& a, const vector<int>& b){
//   return a[0] < b[0];
// });

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, d;
  cin >> n >> d;
  vector<pair<int,int>> people(n);
  rep(i,n) { cin >> people[i].first >> people[i].second;}

  ll len = 1200005;
  vector<int> ans(len,0);
  rep(i,n){
    if(people[i].second-d+1<=people[i].first)continue;
    ans[people[i].first]++;
    ans[people[i].second+1-d]--;
  }

  rep3(i,1,len){
    ans[i] = ans[i] + ans[i-1];
  }

  ll count = 0;
  rep3(i,1,len){
    if(i+d>len-1)break;
    if(ans[i]>=2) {
      count += nCr(ans[i],2);
    }
  }

  cout << count << endl;

  return 0;
}