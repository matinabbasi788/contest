#include <iostream>
#include <vector>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        vector<int> a = {0, 1, 0, 3, 2, 0, 2, 5};
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        int ans = 0;
        for (int i : arr) {
            for (auto it = a.begin(); it != a.end(); it++) {
                if (*it == i) {
                    a.erase(it);
                    break;
                }
            }
            ans++;
            if (a.empty()) {
                break;
            }
        }
        if (a.empty()) {
            cout << ans << "\n";
        } else {
            cout << 0 << "\n";
        }
    }
    return 0;
}

