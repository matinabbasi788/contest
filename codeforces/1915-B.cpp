#include <algorithm>
#include <bits/stdc++.h>
#include <cstdio>
#include <string>
#include <vector>


using namespace std;
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  while(t--){
    string s;
    for (int i = 0; i < 3; i++){
      string temp;
      cin >> temp;
      if (temp.find("?") != string::npos){
        s = temp;
      }
    }
    vector<char> ans = {'A', 'B', 'C'};
    for (int i = 0; i < 3; i++){
      ans.erase(remove(ans.begin(), ans.end(), s[i]), ans.end());
    }
    cout << ans[0] << '\n';
  }
}
