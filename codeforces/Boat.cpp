#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

int main() {
    int n, w;
    cin >> n >> w;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    // Check feasibility
    for (int weight : a) {
        if (weight > w) {
            cout << -1 << endl;
            return 0;
        }
    }
    if (n == 1) {
        cout << 1 << endl;
        return 0;
    }
    vector<int> sorted_a = a;
    sort(sorted_a.begin(), sorted_a.end());
    if (sorted_a[0] + sorted_a[1] > w) {
        cout << -1 << endl;
        return 0;
    }

    // Simulation
    multiset<int> lower(a.begin(), a.end()); // People in Lower
    multiset<int> upper;                     // People in Upper
    string boat_location = "Lower";
    int trips = 0;

    while (!lower.empty()) {
        if (boat_location == "Lower") {
            if (lower.size() >= 2) {
                int lightest = *lower.begin();
                auto it = lower.upper_bound(w - lightest);
                if (it != lower.begin()) {
                    --it;
                    int heaviest_pair = *it;
                    if (heaviest_pair != lightest) {
                        // Send lightest and heaviest_pair
                        lower.erase(lower.find(lightest));
                        lower.erase(lower.find(heaviest_pair));
                        upper.insert(lightest);
                        upper.insert(heaviest_pair);
                    } else {
                        // Send heaviest alone
                        int heaviest = *lower.rbegin();
                        lower.erase(--lower.end());
                        upper.insert(heaviest);
                    }
                } else {
                    // Send heaviest alone
                    int heaviest = *lower.rbegin();
                    lower.erase(--lower.end());
                    upper.insert(heaviest);
                }
            } else { // Only 1 left
                int last = *lower.begin();
                lower.erase(lower.begin());
                upper.insert(last);
            }
            trips++;
            boat_location = "Upper";
        }

        if (!lower.empty() && !upper.empty()) {
            // Return lightest from Upper to Lower
            int lightest_upper = *upper.begin();
            upper.erase(upper.begin());
            lower.insert(lightest_upper);
            trips++;
            boat_location = "Lower";
        }
    }

    cout << trips << endl;
    return 0;
}
