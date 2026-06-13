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

template <typename T>
void show_vector(const vector<T>& a){
  for(int i=0;i<(int)a.size();i++){
    cout << a[i] << (i+1 == (int)a.size() ? "" : " ");
  }
  cout << endl;
}

// sort(ans.begin(),ans.end(),[](const vector<int>& a, const vector<int>& b){
//   return a[0] < b[0];
// });

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  vector<int> a(n);
  for(int i=0;i<n;i++) {cin >> a[i];}

  sort(a.begin(), a.end());

  cout << a[n - 1] << '\n';
  return 0;
}