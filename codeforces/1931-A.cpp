// Author: Matin Abbasi
// Date: 2025-03-31
// Description: [Description]

// Includes
#include <bits/stdc++.h>
using namespace std;


// Solve function
void solve(){
  vector<char> a = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
  int n;
  cin >> n;
  if (n > 52){
    n -= 53;
    cout << a[n] << a[25] << a[25] << '\n';
  } else if (n > 27){
    n -= 28;
    cout << a[0] << a[n] << a[25] << '\n';
  } else{
    n -= 3;
    cout << a[0] << a[0] << a[n] << '\n';
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

