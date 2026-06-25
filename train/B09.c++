#include <iostream>
#include <vector>

using namespace std;

int main(){
  int n;
  cin >> n;
  int len = 1502;
  vector<vector<int>> ans(len, vector<int>(len,0));
  for(int i=0; i<n; i++){
    int a,b,c,d;
    cin >> a >> b >> c >> d;
    ans[c][d]++;
    ans[a][d]--;
    ans[c][b]--;
    ans[a][b]++;
  }
  for(int i=1; i<len; i++){
    for(int j=0; j<len; j++){
      ans[i][j] = ans[i][j] + ans[i-1][j];
    }
  }
  for(int i=1; i<len; i++){
    for(int j=0; j<len; j++){
      ans[j][i] = ans[j][i] + ans[j][i-1];
    }
  }
  int count = 0;
  for(int i=0; i<len; i++){
    for(int j=0; j<len; j++){
      if(ans[i][j]>=1)count++;
    }
  }
  cout << count << endl;
}