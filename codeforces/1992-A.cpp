// Author: Matin Abbasi
// Date: 2025-03-25
// Description: [Description]

// Includes
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;


// Solve function
void solve(){
  int a[3];
  for (int i = 0; i < 3; i++) cin >> a[i];
  for (int i = 0; i < 5; i++){
    for (int j = 0; j < 3; j++){
      if (a[j] == *min_element(a, a + 3)){
        a[j]++;
        break;
      }
    }
  }
  cout << a[0] * a[1] * a[2] << "\n";
}


// Main function
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t = 1;
  cin >> t;
  while(t--){
    solve();
  }
  return 0;
}

