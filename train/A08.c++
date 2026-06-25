#include <iostream>
#include <vector>

using namespace std;

int main(){
  int h, w;
  cin >> h >> w;
  vector<vector<int>> ans(h+1,vector<int>(w+1,0));
  for(int i=1; i<h+1; i++){
    for(int j=1; j<w+1; j++){
      cin >> ans[i][j];
    }
  }

  for(int i=1; i<w+1; i++){
    for(int j=1; j<h+1; j++){
      ans[j][i] = ans[j][i] + ans[j][i-1];
    }
  }

  for(int i=1; i<h+1; i++){
    for(int j=1; j<w+1; j++){
      ans[i][j] = ans[i][j] + ans[i-1][j];
    }
  }

  int q;
  cin >> q;
  for(int i=0; i<q; i++){
    int a,b,c,d;
    cin >> a >> b >> c >> d;
    cout << ans[c][d] - ans[c][b-1] - ans[a-1][d] + ans[a-1][b-1] << endl;
  }
}