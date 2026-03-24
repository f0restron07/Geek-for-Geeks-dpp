import java.util.*;

class Solution {
    public boolean canFinish(int n, int[][] prerequisites) {
        List<List<Integer>> g = new ArrayList<>();
        for (int i = 0; i < n; i++) g.add(new ArrayList<>());
        int[] in = new int[n];
        for (int[] e : prerequisites) {
            g.get(e[1]).add(e[0]);
            in[e[0]]++;
        }
        Queue<Integer> q = new ArrayDeque<>();
        for (int i = 0; i < n; i++) if (in[i] == 0) q.offer(i);
        int c = 0;
        while (!q.isEmpty()) {
            int u = q.poll();
            c++;
            for (int v : g.get(u)) if (--in[v] == 0) q.offer(v);
        }
        return c == n;
    }
}