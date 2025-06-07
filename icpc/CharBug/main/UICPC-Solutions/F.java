import java.io.*;
import java.util.*;

public class mosque {
    private static final int maxn = 300005; // Define a reasonable value for maxn
    private static int[] startingTime = new int[maxn];
    private static int[] finishingTime = new int[maxn];
    private static int[] topEdgeWeight = new int[maxn];
    private static ArrayList<ArrayList<Integer>> g, blocks;
    private static int[] par = new int[maxn];
    private static long[] sumWeights = new long[maxn];

    private static class Fenwick {
        long[] fen = new long[maxn + 1];

        Fenwick() {
            Arrays.fill(fen, 0);
        }

        long get(int p) {
            p = startingTime[p];
            long ans = 0;
            for (p++; p != 0; p ^= p & -p) ans += fen[p];
            return ans;
        }

        void upd(int p, long v) {
            for (p++; p <= maxn; p += p & -p)
                fen[p] += v;
        }

        void upd(int l, int r, long v) { // adds v to range [l, r)
            upd(l, v);
            upd(r, -v);
        }

        void update(int vertex, long value) {
            upd(startingTime[vertex], finishingTime[vertex], value);
        }

        long getPath(int u, int par) {
            return get(u) - get(par);
        }
    }

    private static Integer currentTime = 0;

    private static void getStartingTimeFinishingTime(int vertex) {
        startingTime[vertex] = currentTime++;
        for (int u : g.get(vertex)) {
            getStartingTimeFinishingTime(u);
        }
        finishingTime[vertex] = currentTime;
    }

    private static ArrayList<Integer> reverse(ArrayList<Integer> arrayList) {
        ArrayList<Integer> ret = new ArrayList<>();
        for (int i = arrayList.size() - 1; i >= 0; i--)
            ret.add(arrayList.get(i));
        return ret;
    }

    private static void getBlocks(int v, ArrayDeque<Integer> bls) {
        while (bls.size() > 1 && topEdgeWeight[bls.getLast()] <= 2 * topEdgeWeight[v])
            bls.removeLast();
        bls.addLast(v);
        blocks.get(v).addAll(bls);
        blocks.set(v, reverse(blocks.get(v)));
        for (Integer u : g.get(v)) {
            ArrayDeque<Integer> finalBls = new ArrayDeque<>(bls);
            getBlocks(u, finalBls);
        }
    }

    public static void solve(int n, int q, int[][] edges, int[][] queries) throws IOException {
        PrintWriter out = new PrintWriter(System.out);
        currentTime = 0;
        g = new ArrayList<>();
        blocks = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            g.add(new ArrayList<>());
            blocks.add(new ArrayList<>());
        }

        // Read edges and construct the tree
        for (int i = 1; i < n; i++) {
            int parent = edges[i - 1][0], weight = edges[i - 1][1];
            g.get(parent).add(i); // Child
            topEdgeWeight[i] = weight;
            par[i] = parent;
            sumWeights[i] = sumWeights[parent] + weight;
        }

        getStartingTimeFinishingTime(0);
        getBlocks(0, new ArrayDeque<>());

        Fenwick fenwick = new Fenwick();
        long ans = 0;

        // Process queries
        for (int[] query : queries) {
            int u = query[0], f = query[1];
            int v = -1;

            for (int vCandidate : blocks.get(u)) {
                v = vCandidate;
                if (v == 0 || f + sumWeights[u] - sumWeights[v] + fenwick.getPath(u, par[v]) < topEdgeWeight[v])
                    break;
            }
            out.println(v + 1);

            out.flush();

            fenwick.update(v, f + sumWeights[u] - sumWeights[v] + fenwick.getPath(u, par[v]));
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        // Read n and q
        String[] firstLine = br.readLine().split(" ");
        int n = Integer.parseInt(firstLine[0]);

        // Read edges
        int[][] edges = new int[n - 1][2];
        for (int i = 0; i < n - 1; i++) {
            String[] edgeInput = br.readLine().split(" ");
            edges[i][0] = Integer.parseInt(edgeInput[0]) - 1;
            edges[i][1] = Integer.parseInt(edgeInput[1]);
        }

        // Read queries
        int q = Integer.parseInt(br.readLine());
        int[][] queries = new int[q][2];
        for (int i = 0; i < q; i++) {
            String[] queryInput = br.readLine().split(" ");
            queries[i][0] = Integer.parseInt(queryInput[0]) - 1; // u
            queries[i][1] = Integer.parseInt(queryInput[1]); // f
        }
        br.close();

        // Solve and print the result
        solve(n, q, edges, queries);
    }
}
