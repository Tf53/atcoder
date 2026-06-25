#include <iostream> 
#include <vector>

using namespace std;

int main(){
  int d, n;
  cin >> d >> n;
  vector<int> a(d+1,0);

  for(int i=0; i<n; i++){
    int l, r;
    cin >> l >> r;
    a[l]++;
    a[r+1]--;
  }

  for(int i=1; i<d+1; i++){
    a[i] = a[i] + a[i-1];
  }

  for(int i=1; i<d+1; i++){
    cout << a[i] << endl;
  }
}