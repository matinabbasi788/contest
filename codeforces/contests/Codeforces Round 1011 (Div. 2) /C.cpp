#include <bits/stdc++.h>
using namespace std;

long long findK(long long x, long long y) {
    if (x == y) return -1; // No solution if x equals y
    
    long long k = 0;
    int c_x = 0, c_y = 0; // Carry bits
    
    for (int i = 0; i < 60; i++) {
        int x_i = (x >> i) & 1;
        int y_i = (y >> i) & 1;
        
        int bx = x_i ^ c_x; // Bit of x + k if k_i = 0
        int by = y_i ^ c_y; // Bit of y + k if k_i = 0
        
        if (bx == 1 && by == 1) {
            // Both bits are 1; set k_i = 1 to make them 0
            k |= (1LL << i);
            c_x = x_i | c_x; // Carry when k_i = 1
            c_y = y_i | c_y;
        } else {
            // At least one bit is 0; keep k_i = 0
            c_x = x_i & c_x; // Carry when k_i = 0
            c_y = y_i & c_y;
        }
    }
    
    // Verify k is within bounds
    if (k > 1e18) return -1;
    return k;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        long long x, y;
        cin >> x >> y;
        cout << findK(x, y) << "\n";
    }
    return 0;
}
