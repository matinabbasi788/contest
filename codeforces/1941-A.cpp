#include <bits/stdc++.h>
using namespace std;


int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  while(t--){
    int n, m, k, ans = 0;
    cin >> n >> m >> k;
    int b[n], c[m];
    for (int i = 0; i < n; i++){
      cin >> b[i];
    }
    for (int i = 0; i < m; i++){
      cin >> c[i];
    }
    for (int i = 0; i < n; i++){
      for (int j = 0; j < m; j++){
        if (b[i] + c[j] <= k){
          ans++;
        }
      }
    }
    cout << ans << '\n';
  }
}
