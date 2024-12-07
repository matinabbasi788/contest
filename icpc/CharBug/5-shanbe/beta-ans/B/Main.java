package B;
import java.util.Scanner;

public class Main {

    public static void solve() {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int f = sc.nextInt();

        int ans = 0;
        double mn = 1e9;  // A large number to track the minimum time
        for (int i = 0; i < n; i++) {
            double x = sc.nextDouble();
            double v = sc.nextDouble();
            double time = (f - x) / v;
            if (time < mn) {
                mn = time;
                ans = i;
            }
        }
        System.out.println(ans + 1);
    }

    public static void main(String[] args) {
        int t = 1;
        // t = sc.nextInt(); // Uncomment if there are multiple test cases
        for (int i = 0; i < t; i++) {
            solve();
        }
    }
}
