#include <iostream>
#include <vector>

using namespace std;

int main() {
    int t;
    if (!(cin >> t)) return 1;
    
    while (t--) {
        int n;
        if (!(cin >> n)) return 1;
        
        long long sum = 0;
        int oddCount = 0;
        int maxVal = 0;
        vector<int> a(n);
        
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            sum += a[i];
            if (a[i] % 2 != 0)
                oddCount++;
            if (a[i] > maxVal)
                maxVal = a[i];
        }
        
        if (oddCount == n || oddCount == 0) {
            cout << maxVal << "\n";
        } else {
            long long ans = sum - (oddCount - 1);
            cout << ans << "\n";
        }
    }
    return 0;
}
