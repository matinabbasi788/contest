#include <bits/stdc++.h>
using namespace std;
const int MOD = 998244353;

long long power(long long base, long long exp) {
    long long res = 1;
    base %= MOD;
    while (exp > 0) {
        if (exp & 1) res = res * base % MOD;
        base = base * base % MOD;
        exp >>= 1;
    }
    return res;
}

void solve() {
    long long n, m, A, B;
    cin >> n >> m >> A >> B;
    long long a = A + 1, b = B + 1;
    long long t1 = power(a, n) * power(2, m) % MOD;
    long long t2 = power(b, m) * power(2, n) % MOD;
    long long t3 = power(a, n) * power(b, m) % MOD;
    long long ans = (t1 + t2 - t3 + MOD) % MOD;
    cout << ans << "\n";
}

int main() {
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}
