#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<long long> ax = {1, 2};
    for (int i = 2; i < 17; ++i) {
        ax.push_back(ax[i - 1] + ax[i - 2]);
    }

    int T;
    cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;
        long long a = ax[n - 1];
        long long b = ax[n - 2];

        string ans;
        for (int i = 0; i < m; ++i) {
            long long x, y, z;
            cin >> x >> y >> z;
            vector<long long> v = {x, y, z};
            sort(v.begin(), v.end(), greater<>());
            if (v[0] >= a + b && v[1] >= a && v[2] >= a) {
                ans += '1';
            } else {
                ans += '0';
            }
        }
        cout << ans << '\n';
    }

    return 0;
}

