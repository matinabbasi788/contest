#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int W, H, n;
    cin >> W >> H >> n;
    
    // Store power supplies with (height, original index)
    vector<pii> power_supplies(n);
    for (int i = 0; i < n; i++) {
        cin >> power_supplies[i].first; // height h_i
        power_supplies[i].second = i;   // original index
    }
    
    // Store consumers with (x, y, original index)
    vector<tuple<int, int, int>> consumers(n);
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        consumers[i] = {x, y, i}; // x, y, original index
    }
    
    // Sort consumers by x-coordinate
    sort(consumers.begin(), consumers.end());
    
    // Sort power supplies by height
    sort(power_supplies.begin(), power_supplies.end());
    
    // Assign power supplies to consumers
    vector<int> p(n);
    for (int i = 0; i < n; i++) {
        int power_original_index = power_supplies[i].second;
        int consumer_original_index = get<2>(consumers[i]);
        p[power_original_index] = consumer_original_index + 1; // 1-based index
    }
    
    // Output the result
    for (int i = 0; i < n; i++) {
        cout << p[i];
        if (i < n - 1) cout << " ";
        else cout << "\n";
    }
    
    return 0;
}
