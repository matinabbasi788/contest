package A;
import java.util.Scanner;

public class Main {

    public static void solve() {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int ans = 0;
        for (int i = 0; i < n; i++) {
            int x = sc.nextInt();
            ans += x;
        }
        System.out.println(ans);
    }

    public static void main(String[] args) {
        int t = 1;
        // t = sc.nextInt(); // Uncomment if there are multiple test cases
        for (int i = 0; i < t; i++) {
            solve();
        }
    }
}
