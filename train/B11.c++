#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int search(vector<int> a, int target){
  int pos = lower_bound(a.begin()+1, a.end(),target)-a.begin();
  return pos-1;
}

int main() {
  int n;
  cin >> n;
  vector<int> ans(n+1,0);
  for(int i=1; i<=n; i++){cin >> ans[i];}
  sort(ans.begin()+1,ans.end());
  int q;
  cin >> q;
  for(int i=0; i<q; i++){
    int target;
    cin >> target;
    cout << search(ans,target) << endl;
  }
}