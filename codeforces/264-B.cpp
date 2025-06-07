#include <bits/stdc++.h>
#include <numeric>
#include <system_error>
#include <vector>
using namespace std;


const int MAX_A = 100005;


int main(){
  int n, ans = 0, c = 0, best = 1;
  cin >> n;
  int arr[n];
  for (int i = 0; i < n; i++){
    cin >> arr[i];
  }
  vector<int> dp(MAX_A, 0);
  for (int i = 0; i < n; i++){
    ans = 0;
    c = i;
    for (int j = i; j < n; j++){
      if (gcd(arr[c], arr[j]) > 1){
        ans += 1;
        c = j;
      }
    }
    best = max(best, ans);
  }
  cout << best << '\n';
}
