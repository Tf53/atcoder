#include <iostream>
#include <vector>

using namespace std;

int main(){
  int h, w, n;
  cin >> h >> w >> n;
  vector<vector<int>> ans(h+2,vector<int>(w+2,0));
  for(int i=0; i<n; i++){
    int a,b,c,d;
    cin >> a >> b >> c >> d;
    ans[a][b]++;
    ans[a][d+1]--;
    ans[c+1][b]--;
    ans[c+1][d+1]++;
  }

  for(int i=1; i<h+2; i++){
    for(int j=1; j<w+2; j++){
      ans[i][j] = ans[i][j] + ans[i][j-1];
    }
  }
  for(int i=1; i<w+2; i++){
    for(int j=1; j<h+2; j++){
      ans[j][i] = ans[j][i] + ans[j-1][i];
    }
  }

  for(int i=1; i<h+1; i++){
    for(int j=1; j<w+1; j++){
      cout << ans[i][j] << ' ';
    }
    cout << endl;
  }

}