#include <bits/stdc++.h>
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, k;
  cin >> n >> k;

  vector<long long> a(n);
  for(int i=0;i<n;i++){cin >> a[i];}
  sort(a.begin(), a.end());
  int min_diff = 1000000000;
  for(int i=0;i<n;i++){
    if(n-k+i-1>=n){break;}
    long long len = a[n-k+i-1]-a[i];
    if(min_diff>len){min_diff=len;}
  }
  cout << min_diff << '\n';
  return 0;
}