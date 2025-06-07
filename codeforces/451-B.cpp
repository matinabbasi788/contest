// Author: Matin Abbasi
// Date: 2025-03-28
// Description: [Description]

// Includes
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;


// Solve function
void solve(){
  int n;
  cin >> n;
  int a[n];
  for (int i = 0; i < n; i++){
    cin >> a[i];
  }
  if (is_sorted(a, a + n)){
    cout << "yes" << "\n";
    cout << 1 << " " << 1 << "\n";
    return;
  }
  int x = 0, y = 0;
  for (int i = 0; i < n - 1; i++){
    if (a[i] > a[i+1]){
      y = i + 1;
    } else if (y == 0){
      x = i+1;
    } else{
      break;
    }
  }
  sort(a + x, a + y + 1);
  for (int i = 0; i < n - 1; i++){
    if (a[i] > a[i+1]){
      cout << "no" << "\n";
      return;
    }
  }
  cout << "yes" << "\n";
  cout << x + 1 << " " << y + 1 << "\n";
}


// Main function
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t = 1;
  /*cin >> t;*/
  while(t--){
    solve();
  }
  return 0;
}

