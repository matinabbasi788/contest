#include <algorithm>
#include <bits/stdc++.h>
#include <cstdlib>


using namespace std;
int main(){
  vector<int> v = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  for(auto x : v){
    cout << x << ' ';
  }
  cout << '\n';
  random_shuffle(v.begin(), v.end());
  for(auto x : v){
    cout << x << ' ';
  }
  cout << '\n';
  return 0;
} 


