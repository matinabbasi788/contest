#include <iostream>
using namespace std;

void solve() {
    int t;
    cin >> t;
    while (t--) {
        int x;
        cin >> x;

        // اگر x توانی از ۲ باشد، هیچ y معتبری وجود ندارد.
        if ((x & (x - 1)) == 0) {
            cout << -1 << endl;
        } else {
            // بزرگ‌ترین توان ۲ که در x وجود دارد را پیدا می‌کنیم.
            int y = x & -x; // کمترین بیت 1 تنظیم‌شده در x
            cout << y << endl;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}

