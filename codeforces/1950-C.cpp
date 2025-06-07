// Author: Matin Abbasi
// Date: 2025-03-26
// Description: [Description]

// Includes
#include <bits/stdc++.h>
#include <iomanip>
using namespace std;


// Solve function
void solve(){
  int a, b;
  char c;
  cin >> a >> c >> b;
  if (a == 00){
    cout << 12 << ":" << setw(2) << setfill('0') << b << " AM\n";
  } else if (a < 12){
    cout << setw(2) << setfill('0') << a << ":" << setw(2) << setfill('0') << b << " AM\n";
  } else if (a == 12){
    cout << a << ":" << setw(2) << setfill('0') << b << " PM\n";
  } else{
    cout << setw(2) << setfill('0') << a - 12 << ":" << setw(2) << setfill('0') << b << " PM\n";
  }
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

