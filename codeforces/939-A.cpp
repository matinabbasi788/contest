#include <bits/stdc++.h>
#include <cstdio>
#include <vector>


using namespace std;
int main(){
  int n;
  cin >> n;
  vector<int> a(n+1);
  for (int i = 1; i <= n; i++){
    cin >> a[i];
  }
  for (int i = 1; i <= n; i++){
    int x = a[i];
    int y = a[x];
    int z = a[y];
    if (a[z] == x){
      cout << "YES\n";
      return 0;
    }
  }
  cout << "NO\n";
  return 0;
}
