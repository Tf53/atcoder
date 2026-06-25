#include <iostream>
#include <vector>

using namespace std;

int main(){
  int n;
  cin >> n;
  vector<int> a(n);
  for(int i=0; i<n; i++){cin >> a[i];}

  vector<int> yes(n);
  vector<int> no(n);

  for(int i=0; i<n; i++){
    if(a[i] == 1) yes[i] = 1;
    else no[i] = 1;
  }

  for(int i=1; i<n; i++){
    yes[i] = yes[i] + yes[i-1];
    no[i] = no[i] + no[i-1];
  }

  int q;
  cin >> q;
  for(int i=0; i<q; i++){
    int l, r;
    cin >> l >> r;
    l--; 
    r--;
    int win = yes[r] - yes[l-1];
    int lose = no[r] - no[l-1];
    if(win > lose) cout << "win" << endl;
    else if(lose > win) cout << "lose" << endl;
    else cout << "draw" << endl;
  }
}