#include <bits/stdc++.h>
using namespace std;

int compute_mex(const vector<int>& a, int l, int r) {
    unordered_set<int> s(a.begin() + l - 1, a.begin() + r);
    int mex = 0;
    while (s.count(mex)) mex++;
    return mex;
}

vector<pair<int, int>> find_sequence(vector<int> a) {
    vector<pair<int, int>> seq;
    while (a.size() > 1) {
        if (find(a.begin(), a.end(), 0) == a.end()) {
            seq.push_back({1, a.size()});
            a = {0}; // Simulate final step
        } else {
            int l = 1, r = 2;
            int mex = compute_mex(a, l, r);
            seq.push_back({l, r});
            vector<int> new_a(a.begin(), a.begin() + l - 1);
            new_a.push_back(mex);
            new_a.insert(new_a.end(), a.begin() + r, a.end());
            a = new_a;
        }
    }
    return seq;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];
        auto seq = find_sequence(a);
        cout << seq.size() << "\n";
        for (auto [l, r] : seq) cout << l << " " << r << "\n";
    }
    return 0;
}
