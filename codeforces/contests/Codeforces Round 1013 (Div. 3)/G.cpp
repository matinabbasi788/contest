#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    vector<pair<ll, ll>> tests = {
        {24, 2},
        {123456, 777},
        {6, 4},
        {99, 6},
        {10, 4},
        {99, 4}
    };
    for (auto [s, k] : tests) {
        // If s is a multiple of k, no turns needed
        if (s % k == 0) {
            cout << k << "\n";
            continue;
        }
        // Try each final power p from k down to 1
        ll ans = 1;
        for (ll p = k; p >= 1; p--) {
            ll t = k - p; // Number of turns
            // Use powers k, k-1, ..., p to get as close to s as possible
            ll pos = 0;
            ll curr_power = k;
            ll direction = 1;
            bool can_reach = false;
            for (ll i = 0; i <= t; i++) {
                if (curr_power < p) break;
                // Greedily move towards s
                ll steps = (direction == 1) ? (s - pos) / curr_power : (pos - s) / curr_power;
                if (steps == 0) steps = 1; // Must make at least one stroke
                pos += steps * curr_power * direction;
                if (pos == s) {
                    can_reach = true;
                    break;
                }
                if (pos < 0 || pos > s) break; // Out of bounds
                direction *= -1;
                curr_power = max(1LL, curr_power - 1);
            }
            if (can_reach) {
                ans = p;
                break;
            }
            // If power is 1, we can adjust if the remaining distance is even
            if (curr_power == 1) {
                ll dist = abs(pos - s);
                if (dist % 2 == 0) { // Can reach by moving back and forth
                    ans = 1;
                    break;
                }
            }
        }
        cout << ans << "\n";
    }
    return 0;
}
