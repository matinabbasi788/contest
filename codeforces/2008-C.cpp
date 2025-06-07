#include <bits/stdc++.h>


using namespace std;
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--){
    int l, r, df;
    cin >> l >> r;
    df = r - l;
    int n = 0;
    while (n*(n-1)/2 <= df){
      n++;
    }
    n--;
    cout << n << '\n';
  }
}
