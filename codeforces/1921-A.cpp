#include <algorithm>
#include <bits/stdc++.h>
#include <vector>


using namespace std;
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--){
    vector<pair<int, int>> a;
    for (int i = 0; i < 4; i++){
      int x, y;
      cin >> x >> y;
      a.push_back({x, y});
    }
    auto mn = min_element(a.begin(), a.end());
    auto mx = max_element(a.begin(), a.end());
    int ans = mx->first - mn->first;
    cout << ans * ans << '\n';
  }

}
