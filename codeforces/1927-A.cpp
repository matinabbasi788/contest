#include <bits/stdc++.h>


using namespace std;
int main(){
  ios::sync_with_stdio(0); cin.tie(0);
  int t;
  cin >> t;
  while(t--){
    int n, ans = 0;
    cin >> n;
    string s;
    cin >> s;
    for (int i = 0; i < n; i++){
      if (s[i] == 'B') break;
      ans++;
    }
    for (int i = n-1; i >= 0; i--){
      if (s[i] == 'B') break;
      ans++;
    }
    cout << n - ans << '\n';
  }
}
