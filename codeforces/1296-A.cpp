// Author: Matin Abbasi
// Date: 2025-03-25
// Description: [Description]

// Includes
#include <bits/stdc++.h>
using namespace std;


// Solve function
void solve(){
  int n;
  cin >> n;
  int temp;
  int a[n];
  int even = 0, odd = 0;
  for (int i = 0; i < n; i++){
    cin >> temp;
    if (temp % 2 == 0) even++;
    else odd++;
    a[i] = temp;
  }
  if ((even >= 1 && odd >= 1) || (odd >= 1 && n % 2 == 1)) cout << "YES\n";
  else cout << "NO\n";
  
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

