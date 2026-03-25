class Solution {
    public ArrayList<Integer> minHeightRoot(int V, int[][] edges) {
        ArrayList<Integer> an = new ArrayList<>();
        if (V == 1) {
            an.add(0);
            return an;
        }
        ArrayList<ArrayList<Integer>> aa = new ArrayList<>();
        for (int i = 0; i < V; i++) aa.add(new ArrayList<>());
        int[] dd = new int[V];
        for (int[] e : edges) {
            int u = e[0], v = e[1];
            aa.get(u).add(v);
            aa.get(v).add(u);
            dd[u]++;
            dd[v]++;
        }
        ArrayDeque<Integer> q = new ArrayDeque<>();
        for (int i = 0; i < V; i++) if (dd[i] == 1) q.add(i);
        int rm = V;
        while (rm > 2) {
            int sz = q.size();
            rm -= sz;
            while (sz-- > 0) {
                int u = q.poll();
                for (int v : aa.get(u)) {
                    dd[v]--;
                    if (dd[v] == 1) q.add(v);
                }
            }
        }
        while (!q.isEmpty()) an.add(q.poll());
        Collections.sort(an);
        return an;
    }
}