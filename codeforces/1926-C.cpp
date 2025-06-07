// Author: Matin Abbasi
// Date: 2025-04-19
// Description: [Description]

// Includes
#include <bits/stdc++.h>
using namespace std;

int mem[200005] = {0};

void s_digit(){
  for (int i = 1; i <= 200000; i++){
    int res=0;
    int n = i;
    while(n>0){
      res += n % 10;
      n /= 10;
    }
    mem[i] = mem[i-1] + res;
  }
}

// Solve function
void solve(){
  int n;
  cin >> n;
  cout << mem[n] << '\n';
}


// Main function
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  s_digit();
  int t = 1;
  cin >> t;
  while(t--){
    solve();
  }
  return 0;
}

