#include <iostream>
#include <vector>

using namespace std;

int main(){
  int n;
  cin >> n;
  int len = 1501;
  vector<vector<int>> ans(len,vector<int>(len,0));
  for(int i=0; i<n; i++){
    int x, y;
    cin >> x >> y;
    ans[x][y]++;
  }
  
  for(int i=1; i<len; i++){
    for(int j=1; j<len; j++){
      ans[i][j] = ans[i][j] + ans[i][j-1];
    }
  }
  for(int i=1; i<len; i++){
    for(int j=1; j<len; j++){
      ans[j][i] = ans[j][i] + ans[j-1][i];
    }
  }

  int q;
  cin >> q;
  for(int i=0; i<q; i++){
    int a,b,c,d;
    cin >> a >> b >> c >> d;
    cout << ans[c][d]+ans[a-1][b-1]-ans[c][b-1]-ans[a-1][d] << endl;
  }
}