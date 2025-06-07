#include <bits/stdc++.h>

#define int long long
#define vi vector<int>
#define ii pair<int, int>
#define f first
#define s second
#define all(x) (x).begin(), (x).end()
#define P 31
#define mod 1'000'000'007
#define inf 1'000'000'000'000
#define pb push_back
#define str string
#define sz(x) (x).size()
#define vvi vector<vi>
#define fun function
#define oopt cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(false);
#define file freopen("problemname.in", "r", stdin); freopen("pr.out", "w", stdout);
#define dbg(v) cout << "Line(" << __LINE__ << ") -> " << #v << " = " << (v) << endl;

using namespace std;
template <class T, int SZ> using arr = array<T, SZ>;

char a[4001][4001];
int ds[4001][4001];
vector<ii> pr = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

signed main()
{
	oopt;
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
		{
			cin >> a[i][j];
			ds[i][j] = inf;
		}
	ds[0][0] = 1;
	int rez = 1;
	deque<ii> dq;
	dq.pb({0, 0});
	while (dq.size())
	{
		ii t = dq.front();
		dq.pop_front();
		rez = max(rez, ds[t.f][t.s]);
		for (ii d : pr)
		{
			int i = t.f+d.f, j = t.s+d.s;
			if (i < 0 || j < 0 || i >= n || j >= m || a[i][j] == '.') continue;
			if (ds[i][j] > ds[t.f][t.s]+(a[i][j] != a[t.f][t.s]))
			{
				ds[i][j] = ds[t.f][t.s]+(a[i][j] != a[t.f][t.s]);
				if (a[i][j] == a[t.f][t.s])
					dq.push_front({i, j});
				else
					dq.pb({i, j});
			}
		}
	}
	cout << rez << "\n";
	return 0;
}

