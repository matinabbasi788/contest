package C;
import java.util.*;

public class Main {

    public static int sign(double x) {
        double eps = 1e-9;
        return (x > eps) ? 1 : (x < -eps) ? -1 : 0;
    }

    public static double calc(double[] a, double[] b, double[] c) {
        double m = (b[1] - a[1]) / (b[0] - a[0]);
        double y = m * (c[0] - a[0]) + a[1];
        return Math.abs(y - c[1]);
    }

    public static void solve() {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        double[][] tp = new double[n][2];

        for (int i = 0; i < n; i++) {
            tp[i][0] = sc.nextDouble();
            tp[i][1] = sc.nextDouble();
        }

        double delta = sc.nextDouble();
        
        int[] dp = new int[n];
        Arrays.fill(dp, 2000);
        dp[0] = 1;

        for (int i = 1; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (dp[j] + 1 < dp[i]) {
                    boolean f = true;
                    for (int k = j + 1; k < i; k++) {
                        if (sign(calc(tp[i], tp[j], tp[k]) - delta) > 0) {
                            f = false;
                            break;
                        }
                    }
                    if (f) {
                        dp[i] = dp[j] + 1;
                    }
                }
            }
        }
        System.out.println(dp[n - 1]);
    }

    public static void main(String[] args) {
        int t = 1;
        // t = sc.nextInt();  // Uncomment if there are multiple test cases
        for (int i = 0; i < t; i++) {
            solve();
        }
    }
}
