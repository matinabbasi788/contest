#include <algorithm>
#include <bits/stdc++.h>


using namespace std;
int main(){
  int t;
  cin >> t;
  while (t--){
    int n;
    long long ans = 0;
    cin >> n;
    long long a[n];
    long long b[n];
    for (int i = 0; i < n; i++){
      cin >> a[i];
    }
    for (int i = 0; i < n; i++){
      cin >> b[i];
    }
    long long mna = *min_element(a, a + n);
    long long mnb = *min_element(b, b + n);

    for (int i = 0; i < n; i++){
      int x, y;
      x = a[i] - mna;
      y = b[i] - mnb;
      ans += min(x, y) + max(x, y) - min(x, y);
      /*if (a[i] >= b[i] && a[i] > mna){*/
      /*  ans += a[i] - mna;*/
      /*} else{*/
      /*  ans += b[i] - mnb;*/
      /*}*/
    }
    cout << ans << "\n";

  }
}
