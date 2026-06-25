#include <iostream>
#include <vector>

using namespace std;

int binary_search(vector<int> a, int target){
  int left = 1;
  int right = a.size();
  while(left<=right){
    int mid = (left + right)/2;
    if(a[mid] < target){ left = mid+1;}
    else if(a[mid] == target){ return mid;}
    else right = mid-1;
  }
  return -1;
}

int main(){
  int n, x;
  cin >> n >> x;
  vector<int> ans(n+1);
  for(int i=1; i<=n; i++){cin >> ans[i];}
  int a = binary_search(ans,x);
  cout << a << endl;
}