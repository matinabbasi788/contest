// Author: Matin Abbasi
// Date: {{DATE}}
// Description: [Description]

// Includes
#include <bits/stdc++.h>
using namespace std;


// Solve function
void solve(){
  int a, b;
  cin >> a >> b;
  cout << lcm(a, b) << '\n';
}


// Main function
int main() {
  int t = 1;
  cin >> t;
  while(t--){
    solve();
  }
  return 0;
}
