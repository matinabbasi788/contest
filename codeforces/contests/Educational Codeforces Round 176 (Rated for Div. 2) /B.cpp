#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t; // Number of test cases
    for (int test = 0; test < t; ++test) {
        int n, k;
        cin >> n >> k; // Array size and number of initially blue elements
        vector<long long> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i]; // Read array elements
        }
        sort(a.begin(), a.end(), greater<long long>());
        long long sum = 0;
        for (int i = 0; i <= k; ++i) { // k+1 elements (0 to k inclusive)
            sum += a[i];
        }
        cout << sum << "\n"; // Output the result
    }
    return 0;
}
