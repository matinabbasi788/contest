#include <bits/stdc++.h>
using namespace std;

const int MAXN = 500010; // Maximum array size
const int MAXA = 1000010; // Maximum value in array

int n;
int a[MAXN];
int dp[MAXN];

// Fenwick Tree for maximum value (stores max dp value for each prefix)
struct Fenwick {
    vector<int> bit;
    int size;

    Fenwick(int sz) : size(sz) {
        bit.assign(sz + 1, 0);
    }

    void update(int idx, int val) {
        for (; idx <= size; idx += idx & (-idx)) {
            bit[idx] = max(bit[idx], val);
        }
    }

    int query(int idx) {
        int res = 0;
        for (; idx > 0; idx -= idx & (-idx)) {
            res = max(res, bit[idx]);
        }
        return res;
    }
};

// Fenwick Tree for frequency (counts occurrences of values)
struct FenwickFreq {
    vector<int> bit;
    int size;

    FenwickFreq(int sz) : size(sz) {
        bit.assign(sz + 1, 0);
    }

    void update(int idx, int val) {
        for (; idx <= size; idx += idx & (-idx)) {
            bit[idx] += val;
        }
    }

    int query(int idx) {
        int res = 0;
        for (; idx > 0; idx -= idx & (-idx)) {
            res += bit[idx];
        }
        return res;
    }
};

void solve() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    Fenwick dp_tree(MAXA);      // Tracks max dp value for each value
    FenwickFreq freq_tree(MAXA); // Tracks frequency of values
    int ans = 1;                // Minimum length is 1 (single element)

    for (int r = 1; r <= n; r++) {
        // Get max dp for values < a[r]
        int max_prev = dp_tree.query(a[r] - 1);
        // Get count of elements < a[r] up to position r-1
        int total_less = freq_tree.query(a[r] - 1);

        // Compute dp[r]
        dp[r] = 1 + max_prev; // Extend best prior subsequence
        if (max_prev > 0) {
            // If there's a prior subsequence, consider middle elements
            dp[r] = max(dp[r], 2 + total_less);
        }

        // Update global answer
        ans = max(ans, dp[r]);

        // Update Fenwick Trees with current position
        dp_tree.update(a[r], dp[r]);
        freq_tree.update(a[r], 1);
    }

    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t; // Number of test cases
    while (t--) {
        solve();
    }
    return 0;
}
