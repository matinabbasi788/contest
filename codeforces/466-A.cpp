#include <bits/stdc++.h>


using namespace std;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m, a, b, ans = 0;
    cin >> n >> m >> a >> b;
    double temp = n;
    while (n){
        if (n >= m && b/m <= a){
            n -= m;
            ans += b;
        }else{
            --n;
            ans += a;
        }
    }
    cout << min(ans, int(ceil(temp/m)) * b) << endl;
}