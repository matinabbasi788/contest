#include <bits/stdc++.h>
using namespace std;

void solve(int n) {
    if (n == 1) {
        cout << "1\n";
        return;
    }
    
    if (n % 2 == 0) {
        cout << "-1\n";
        return;
    }
    
    vector<int> perm(n);
    for (int i = 0; i < n; i++) {
        perm[i] = (n - i + 1) % n;
        if (perm[i] == 0) perm[i] = n; // Adjust 0 to n
    }
    
    for (int i = 0; i < n; i++) {
        cout << perm[i];
        if (i < n - 1) cout << " ";
    }
    cout << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        solve(n);
    }
    
    return 0;
}
