#include <bits/stdc++.h>


using namespace std;
int main(){
    int t, a[3], n;
    cin >> t;
    while(t--){
        cin >> a[0] >> a[1] >> a[2] >> n;
        sort(a, a + 3);
        n -= 2 * a[2] - a[1] - a[0];
        if (n < 0 || n % 3 != 0){
            cout << "NO" << endl;
        }else{
            cout << "YES" << endl;
        }
    }
}