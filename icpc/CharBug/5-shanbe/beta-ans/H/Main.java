import java.util.*;

public class Main {

    public static void solve() {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int m = sc.nextInt();
        sc.nextLine(); // to consume the leftover newline character

        char[][] g = new char[n][m];
        for (int i = 0; i < n; i++) {
            g[i] = sc.nextLine().toCharArray();
        }

        int[][] dp = new int[n][m];
        int ans = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (i != 0) {
                    dp[i][j] = dp[i - 1][j];
                    if (j - 1 >= 0) {
                        dp[i][j] = Math.max(dp[i][j], dp[i - 1][j - 1]);
                    }
                    if (j + 1 < m) {
                        dp[i][j] = Math.max(dp[i][j], dp[i - 1][j + 1]);
                    }
                }

                if (g[i][j] == 'B') {
                    dp[i][j]++;
                }

                if (g[i][j] == 'W') {
                    ans = Math.max(ans, dp[i][j]);
                    dp[i][j] = 0;
                }
            }
        }

        System.out.println(ans);
    }

    public static void main(String[] args) {
        // Uncomment to handle multiple test cases
        // Scanner sc = new Scanner(System.in);
        // int t = sc.nextInt();
        // while (t-- > 0) {
        //     solve();
        // }

        solve(); // for single test case
    }
}
