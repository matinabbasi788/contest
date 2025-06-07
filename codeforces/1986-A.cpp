#include <algorithm>
#include <bits/stdc++.h>
#include <iostream>
#include <vector>


using namespace std;
int main(){
  int n;
  cin >> n;
  for (int i = 0; i < n; i++){
    vector<int> a(3);
    cin >> a[0] >> a[1] >> a[2];
    auto min_value = min_element(a.begin(), a.end());
    auto max_value = max_element(a.begin(), a.end());
    cout << int(min_value) << ' ' << int(max_value) << '\n';
    cout << abs(max_value - min_value) << '\n';
  }
}
