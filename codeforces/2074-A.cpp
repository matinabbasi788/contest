// Author: Matin Abbasi
// Date: 2025-03-29
// Description: [Description]

// Includes
#include <bits/stdc++.h>
using namespace std;


// Solve function
void solve(){
  set<int> a;
  for (int i = 0; i < 4; i++){
    int temp;
    cin >> temp;
    a.insert(temp);
  }
  if (a.size() == 1){
    cout << "Yes\n";
  } else{
    cout << "No\n";
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

