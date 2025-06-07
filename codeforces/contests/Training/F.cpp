#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int f(int k, ll a, ll b, ll l1, ll r1, ll l2, ll r2) {
    ll p = a * (1LL << k);      // Left x-coordinate
    ll q = p + (1LL << k);      // Right x-coordinate
    ll r = b * (1LL << k);      // Bottom y-coordinate
    ll s = r + (1LL << k);      // Top y-coordinate
    
    if (k == 0) {
        if (l1 <= p && q <= r1 && l2 <= r && s <= r2) return 1;
        return 0;
    }
    
    if (l1 <= p && q <= r1 && l2 <= r && s <= r2) return 1;
    if (q <= l1 || p >= r1 || s <= l2 || r >= r2) return 0;
    
    return f(k-1, 2*a, 2*b, l1, r1, l2, r2) +
           f(k-1, 2*a+1, 2*b, l1, r1, l2, r2) +
           f(k-1, 2*a, 2*b+1, l1, r1, l2, r2) +
           f(k-1, 2*a+1, 2*b+1, l1, r1, l2, r2);
}

void solve() {
    ll l1, r1, l2, r2;
    cin >> l1 >> r1 >> l2 >> r2;
    cout << f(20, 0, 0, l1, r1, l2, r2) << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}
