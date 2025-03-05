#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
using ll = long long;

void solve()
{
    ll n;
    cin >> n;
    if (n < 5)
    {
        cout << 0;
        return;
    }

    ll res = 0;
    while (n >= 5)
    {
        n /= 5;
        res += n;
    }

    cout << res;
}

int main()
{
    solve();
    return 0;
}