#include <bits/stdc++.h>
using namespace std;


int main(){
  int n, m;
  cin >> n >> m;
  unordered_map<string, string> a;

  for (int i = 0; i < m; i++){
    string x, y;
    cin >> x >> y;
    if (x.length() > y.length()) {
      a[x] = y;
    } else{
      a[y] = x;
    }
  }

  vector<string> b(n);
  for (int i = 0; i < n; i++){
    cin >> b[i];
  }

  for (int i = 0; i < n; i++){
    if (a.find(b[i]) == a.end()) {
      cout << b[i] << " ";
    } else {
      cout << a[b[i]] << " ";
    }
  }
  return 0;
  
}
