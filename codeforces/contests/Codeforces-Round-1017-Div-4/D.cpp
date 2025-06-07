// Author: Matin Abbasi
// Date: 2025-04-13
// Description: [Description]

// Includes
#include <bits/stdc++.h>
using namespace std;


// Solve function
void solve(){
  string a, b;
  cin >> a >> b;
  int i=0, j=0;
  if ((int)b.length() > 2 * (int)a.length()){
    cout << "NO\n";
    return;
  }
  while (i < (int)a.length() && j < (int)b.length()){
    if (j < (int)b.length()-1 && a[i] == b[j] && a[i] == b[j+1]){
        i++;
        j += 2;
    }
    else if (a[i] == b[j]){
      i++;
      j++;
    }
    else{
      cout << "NO\n";
      return;
    }
  }
  cout << "YES\n";
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

