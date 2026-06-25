#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
  int n;
  cin >> n;
  vector<int> a(n+1,0);
  for(int i=1; i<=n; i++){
    cin >> a[i];
  }
  vector<int> ans1(n+1,0);
  vector<int> ans2(n+1,0);
  int mx = 0;
  for(int i=1; i<=n; i++){
    mx = max(mx,a[i]);
    ans1[i] = mx;
  }
  mx = 0;
  for(int i=n; i>=1; i--){
    mx = max(mx,a[i]);
    ans2[i] = mx;
  }
  
  int d;
  cin >> d;
  for(int i=0; i<d; i++){
    int l, r;
    cin >> l >> r;
    int left = ans1[l-1];
    int right = ans2[r+1];
    cout << max(left,right) << endl;
  }
}