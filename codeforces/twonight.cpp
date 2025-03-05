#include <bits/stdc++.h>
#include <algorithm>
using namespace std;

using ll = long long;

#define rep(i, start, end) for (int i = start; i < end; i++)
#define all(x) x.begin(), x.end()

template <typename T>
T maximom(vector<T> n)
{
    T m = -1;
    for (T x : n)
    {
        m = max(m, x);
    }
    return m;
}
template <typename T>
T pow(T number, int power)
{
    T m = 1;
    rep(i, 0, power)
    {
        m = m * number;
    }
    return m;
}



int cul(int i, int j, int x, int y)
{
    int num = 0; // Count of *valid* knight moves from (i,j)
    int x1, y1, x2, y2, x3, y3, x4, y4;
    x1 = i + 2;
    y1 = j + 1;
    x2 = i + 1;
    y2 = j + 2;
    x3 = i - 2;
    y3 = j + 1;
    x4 = i - 1;
    y4 = j + 2;

    // cout << i << " " << j << '\n'; // Debug output

    if ((x1 >= 1 && x1 <= x) && (y1 >= 1 && y1 <= y))
    { // Check if (x1, y1) is within bounds
        // cout << "check 1" << '\n'; // Debug output
        num++;
    }
    if ((x2 >= 1 && x2 <= x) && (y2 >= 1 && y2 <= y))
    { // Check if (x2, y2) is within bounds
        // cout << "check 2" << '\n'; // Debug output
        num++;
    }
    if ((x3 >= 1 && x3 <= x) && (y3 >= 1 && y3 <= y))
    { // Check if (x3, y3) is within bounds
        // cout << "check 3" << '\n'; // Debug output
        num++;
    }
    if ((x4 >= 1 && x4 <= x) && (y4 >= 1 && y4 <= y))
    { // Check if (x4, y4) is within bounds
        // cout << "check 4" << '\n'; // Debug output
        num++;
    }
    // cout << num << "=this is t " << "\n"; // Debug output
    return num; // Return count of valid knight moves
}

void solve()
{

    // 1+2+2+4+4+4+5+6
    int n;
    cin >> n;
    if (n >= 1)
    {
        cout << 0 << '\n';
    }
    if (n >= 2)
    {
        cout << 6 << '\n';
    }
    rep(z, 3, n + 1)
    {
        ll cnt = 1;
        ll res = 0;
        ll f = z * z;
        // cout << f << "----\n";
        rep(i, 1, z + 1)
        {
            rep(j, 1, z + 1)
            {
                int t = cul(i, j, z, z);
                // cout << i << " " << j << " " << z << " " << z << " " << t << "\n";
                ll value = (f - cnt - t);
                // cout << value << "+++++++" << '\n';

                res = res + value;
                cnt++;
            }
        }
        cout << res << "\n";
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    {
        solve();
    }
    return 0;
}
