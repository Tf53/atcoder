#include <bits/stdc++.h>
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define rep3(i,m,n) for(int i=(int)(m);i<(int)(n);i++)
#define ll long long

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

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  vector<ll> x(n);
  vector<ll> p(n);
  rep(i,n){cin >> x[i];}
  rep(i,n){cin >> p[i];}

  vector<ll> sum_people(n+1);
  sum_people[0]=0;
  rep3(i,1,n+1){
    sum_people[i]=sum_people[i-1]+p[i-1];
  }

  int q;
  cin >> q;
  for(int i=0;i<q;i++){
    ll left, right;
    cin >> left >> right;
    int left_index = binary_search_higher(x,left);
    int right_index = binary_search_less(x,right);
    if(left_index<=right_index){
      cout << sum_people[right_index+1]-sum_people[left_index] << endl;
    }
    else {
      cout << 0 << '\n';
    }
  }

  return 0;
}