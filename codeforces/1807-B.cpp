#include <bits/stdc++.h>

using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    int even = 0, odd = 0;
    for (int i = 0; i < n; i++) {
      if (a[i] % 2 == 0) {
        odd += a[i];
      } else {
        even += a[i];
      }
    }
    string res = (even >= odd) ? "NO" : "YES";
    cout << res << "\n";
  }
}
