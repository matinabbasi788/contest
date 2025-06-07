#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);

        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }

        int maxVal = *max_element(a.begin(), a.end());
        int minVal = *min_element(a.begin(), a.end());

        cout << maxVal - minVal << endl;
    }
}

