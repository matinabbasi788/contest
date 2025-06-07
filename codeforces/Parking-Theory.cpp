#include <bits/stdc++.h>
using namespace std;

const int MAXN = 505;
int n, m;
int grid[MAXN][MAXN];
int left_smaller[MAXN][MAXN], right_smaller[MAXN][MAXN];
int above_smaller[MAXN][MAXN], below_smaller[MAXN][MAXN];
bool B[MAXN][MAXN];

void compute_smaller() {
    for (int i = 1; i <= n; i++) {
        stack<int> st;
        for (int j = 1; j <= m; j++) {
            while (!st.empty() && grid[i][st.top()] >= grid[i][j]) st.pop();
            left_smaller[i][j] = st.empty() ? 0 : st.top();
            st.push(j);
        }
    }
    for (int i = 1; i <= n; i++) {
        stack<int> st;
        for (int j = m; j >= 1; j--) {
            while (!st.empty() && grid[i][st.top()] >= grid[i][j]) st.pop();
            right_smaller[i][j] = st.empty() ? m + 1 : st.top();
            st.push(j);
        }
    }
    for (int j = 1; j <= m; j++) {
        stack<int> st;
        for (int i = 1; i <= n; i++) {
            while (!st.empty() && grid[st.top()][j] >= grid[i][j]) st.pop();
            above_smaller[i][j] = st.empty() ? 0 : st.top();
            st.push(i);
        }
    }
    for (int j = 1; j <= m; j++) {
        stack<int> st;
        for (int i = n; i >= 1; i--) {
            while (!st.empty() && grid[st.top()][j] >= grid[i][j]) st.pop();
            below_smaller[i][j] = st.empty() ? n + 1 : st.top();
            st.push(i);
        }
    }
}

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> grid[i][j];
        }
    }
    compute_smaller();
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            B[i][j] = (left_smaller[i][j] >= 1 && right_smaller[i][j] <= m &&
                       above_smaller[i][j] >= 1 && below_smaller[i][j] <= n);
        }
    }
    long long ans = 0;
    for (int r1 = 1; r1 <= n; r1++) {
        for (int r2 = r1; r2 <= n; r2++) {
            vector<bool> bad(m + 1, false);
            if (r2 - r1 >= 2) {
                for (int i = r1 + 1; i <= r2 - 1; i++) {
                    for (int j = 1; j <= m; j++) {
                        if (B[i][j]) bad[j] = true;
                    }
                }
            }
            int next_true = m + 1;
            long long sum = 0;
            for (int c1 = m; c1 >= 1; c1--) {
                if (bad[c1]) next_true = c1;
                sum += next_true - c1;
            }
            ans += sum;
        }
    }
    cout << ans << endl;
    return 0;
}
