#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#include <utility>
#include <algorithm>
#include <cstring>

int x, p, q;
std::vector<int> arr;
int dp[2001][2001];
int next[2][2001];

int solve(int pos, int k) {
	if (k>q) {
		return 0x3f3f3f3f;
	}
	if (pos==x) {
		return 0;
	}
	if (dp[pos][k]!=-1) {
		return dp[pos][k];
	}

	int ret = solve(next[1][pos],k+1);
	for (int i = pos; i < next[0][pos]; i++) {
		ret = std::min(ret, 1 + solve(i+1,k));
	}

	return dp[pos][k] = ret;
}

bool can_solve(int cap) {
	for (int i = 0; i < 2; i++) {
		for (int l = x-1, r = x-1; l >= 0; l--) {
			while (arr[r]-arr[l]+1>(i+1)*cap) {
				--r;
			}

			next[i][l] = r+1;
		}
	}

	memset(dp,-1,sizeof(dp));
	return solve(0,0) <= p;
}

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	std::cin >> x >> p >> q;

	// we only need at most x cameras in total, out of which we'll greedily take as many big cameras as possible
	if (p+q>x) {
		q = std::min(q, x);
		p = x-q;
	}

	for (int i = 0, tmp; i < x; i++) {
		std::cin >> tmp;
		arr.emplace_back(tmp);
	}

	std::sort(arr.begin(),arr.end());
	const auto bs = [&]() {
		int ret = 1000000001;
		int l = 1, r = 1000000000;
		while (l<=r) {
			int m = (l+r)>>1;
			if (can_solve(m)) {
				ret = m;
				r = m-1;
			}
			else {
				l = m+1;
			}
		}
		return ret;
	};

	std::cout << bs() << "\n";
	//can_solve(bs(),1);
}

