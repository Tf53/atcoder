#include <iostream>
#include <string>

using namespace std;

int main(){
  int n;
  cin >> n;
  string s = to_string(n);
  int count = 0;

  for(int i=0; i<s.size(); i++){
    if(s[s.size()-i-1] == '1') count += (1 << i);
  }
  cout << count << endl;
}