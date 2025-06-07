#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    for (int test = 0; test < t; ++test) {
        int n, k;
        string s;
        cin >> n >> k >> s;
        
        bool all_same = true;
        for (char c : s) {
            if (c != s[0]) {
                all_same = false;
                break;
            }
        }
        if (all_same) {
            cout << "NO" << endl;
            continue;
        }
        
        string rev_s = s;
        reverse(rev_s.begin(), rev_s.end());
        if (s < rev_s) {
            cout << "YES" << endl;
        }
        else {
            if (k >= 1) {
                cout << "YES" << endl;
            } else {
                cout << "NO" << endl;
            }
        }
    }
    return 0;
}
