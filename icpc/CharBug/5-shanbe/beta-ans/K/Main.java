package K;
import java.util.*;

public class Main {

    public static void solve() {
        Scanner sc = new Scanner(System.in);
        int k = sc.nextInt();
        int q = sc.nextInt();
        sc.nextLine();  // Consume newline after reading integers

        Map<String, Integer> win = new HashMap<>();
        Map<String, String> lose = new HashMap<>();
        List<String>[] wins = new List[20];
        for (int i = 0; i < 20; i++) {
            wins[i] = new ArrayList<>();
        }
        Map<String, Integer> rnk = new HashMap<>();

        for (int i = 0; i < (1 << k) - 1; i++) {
            String s1 = sc.next();
            String p1 = sc.next();
            sc.next();  // Ignore zz
            String p2 = sc.next();
            String s2 = sc.next();

            int point1, point2;
            if (p1.contains("(")) {
                int pos1 = p1.indexOf('(');
                int pos2 = p2.indexOf('(');
                point1 = Integer.parseInt(p1.substring(pos1 + 1, p1.length() - 1));
                point2 = Integer.parseInt(p2.substring(pos2 + 1, p2.length() - 1));
            } else {
                point1 = Integer.parseInt(p1);
                point2 = Integer.parseInt(p2);
            }

            if (point1 > point2) {
                win.put(s1, win.getOrDefault(s1, 0) + 1);
                lose.put(s2, s1);
                win.put(s2, win.getOrDefault(s2, 0));
            } else {
                win.put(s2, win.getOrDefault(s2, 0) + 1);
                lose.put(s1, s2);
                win.put(s1, win.getOrDefault(s1, 0));
            }
        }

        for (String team : win.keySet()) {
            wins[win.get(team)].add(team);
        }

        rnk.put(wins[k].get(0), 0);
        for (int i = k - 1; i >= 0; i--) {
            for (String x : wins[i]) {
                rnk.put(x, rnk.get(lose.get(x)) + (1 << i));
            }
        }

        for (int i = 0; i < q; i++) {
            String s1 = sc.next();
            String s2 = sc.next();
            int x1 = rnk.get(s1), x2 = rnk.get(s2);
            int ans = 0;
            while (x1 != x2) {
                x1 /= 2;
                x2 /= 2;
                ans++;
            }
            System.out.println(ans);
        }
    }

    public static void main(String[] args) {
        solve();
    }
}
