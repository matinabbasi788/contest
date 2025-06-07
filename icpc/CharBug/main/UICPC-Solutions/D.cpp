#include <bits/stdc++.h>

using namespace std;

const int maxQ = 1e5;
const int maxN = 1e9;
 
typedef long long ll;
 
int main()
{
    int q;
    cin >> q;
    while(q--){
        ll a;
        cin >> a;
        if(a < 10){
            cout << (a>=4 ? 20ll:a*(9-a)) << '\n';
        }
        else{
            int tmpa = a;
            ll w = 1;
            while(tmpa >= 10){
                w *= 10;
                tmpa /= 10;
                w += 1;
            }
            w *= 9;
            ll wp = w/10;
            if(a >= (w+1)/2-1){
                cout << ((w+1)/2-1) * (w+1)/2 << '\n';
                continue;
            }
            if(((wp+1)/2-1)*((wp+1)/2) > a*(w-a)){
                cout << ((wp+1)/2-1)*((wp+1)/2) << '\n';
            }
            else{
                cout << a*(w-a) << '\n';
            }
        }
    }
}
