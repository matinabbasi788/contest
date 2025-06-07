#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    long long x;
    cin >> n >> x;
    
    vector<long long> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    // Sort in descending order
    sort(a.begin(), a.end(), greater<long long>());
    
    int teams = 0;
    int i = 0;
    
    while(i < n) {
        // Calculate minimum team size needed with current skill
        long long min_team_size = (x + a[i] - 1) / a[i]; // Ceiling division
        
        // Check if we have enough remaining students
        if(n - i >= min_team_size) {
            teams++;
            i += min_team_size;
        } else {
            break;
        }
    }
    
    cout << teams << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    
    while(t--) {
        solve();
    }
    
    return 0;
}
