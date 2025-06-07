#include <bits/stdc++.h>
using namespace std;

int compute_mex(vector<int>& a, int l, int r) {
    unordered_set<int> s(a.begin() + l - 1, a.begin() + r);
    int mex = 0;
    while (s.count(mex)) mex++;
    return mex;
}

vector<pair<int, int>> find_sequence(vector<int> a) {
    vector<pair<int, int>> sequence;
    while (a.size() > 1) {
        int n = a.size();
        if (compute_mex(a, 1, n) == 0) {
            sequence.push_back({1, n});
            a = {0};
            break;
        }
        bool found = false;
        int chosen_l = -1, chosen_r = -1;
        for (int l = 1; l < n && !found; l++) {
            for (int r = l + 1; r <= n; r++) {
                if (compute_mex(a, l, r) == 0) {
                    chosen_l = l;
                    chosen_r = r;
                    found = true;
                    break;
                }
            }
        }
        if (found) {
            int mex = 0;
            vector<int> new_a;
            for (int i = 0; i < chosen_l - 1; i++) new_a.push_back(a[i]);
            new_a.push_back(mex);
            for (int i = chosen_r; i < n; i++) new_a.push_back(a[i]);
            sequence.push_back({chosen_l, chosen_r});
            a = new_a;
        } else {
            int mex = compute_mex(a, 1, 2);
            vector<int> new_a;
            new_a.push_back(mex);
            for (int i = 2; i < n; i++) new_a.push_back(a[i]);
            sequence.push_back({1, 2});
            a = new_a;
        }
    }
    return sequence;
}

int main() {
    int t;
    cin >> t;
    for (int test = 0; test < t; test++) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        vector<pair<int, int>> sequence = find_sequence(a);
        cout << sequence.size() << "\n";
        for (auto& p : sequence) {
            cout << p.first << " " << p.second << "\n";
        }
    }
    return 0;
}
