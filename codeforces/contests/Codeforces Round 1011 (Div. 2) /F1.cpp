#include <iostream>
#include <vector>
#include <climits>
using namespace std;

void solve() {
    int t;
    cin >> t;
    
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<int> a(n);
        vector<vector<int>> pos(k + 1);
        
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            pos[a[i]].push_back(i);
        }

        int min_swaps = INT_MAX;

        for (int start = 0; start < n; start++) {
            vector<int> last_seen(k + 1, -1);
            int count = 0, end = start;

            while (end < n && count < k) {
                if (last_seen[a[end]] == -1) {
                    count++;
                }
                last_seen[a[end]] = end;
                end++;
            }

            if (count == k) {
                min_swaps = min(min_swaps, end - start - k);
            }
        }

        cout << min_swaps << "\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}

