#include <bits/stdc++.h>


using namespace std;
int main(){
  int n, ans = 0;
  cin >> n;
  for (int i = 1; i < int(n / 2) + 1; i++){
    if ((n - i) % i == 0){
      ans++;
    }
  }
  cout << ans << "\n";
}
