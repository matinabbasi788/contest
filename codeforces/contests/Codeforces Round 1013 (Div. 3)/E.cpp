#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 10000007;
vector<bool> is_prime(MAX_N, true);
vector<int> primes;

void sieve() {
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i * i < MAX_N; i++) {
        if (is_prime[i]) {
            for (int j = i * i; j < MAX_N; j += i) {
                is_prime[j] = false;
            }
        }
    }
    for (int i = 2; i < MAX_N; i++) {
        if (is_prime[i]) {
            primes.push_back(i);
        }
    }
}

int main() {
    sieve();
    int t;
    scanf("%d", &t);
    while (t--) {
        int n;
        scanf("%d", &n);
        long long ans = 0;
        for (int p : primes) {
            if (p > n) break;
            ans += (n / p);
        }
        printf("%lld\n", ans);
    }
    return 0;
}
