class Solution {
    public int longestCycle(int V, int[][] edges) {

        int[] next = new int[V];
        for (int i = 0; i < V; i++) next[i] = -1;

        for (int[] e : edges) {
            next[e[0]] = e[1];
        }

        boolean[] visited = new boolean[V];
        int maxCycle = -1;

        for (int i = 0; i < V; i++) {

            if (visited[i]) continue;

            int curr = i;
            int step = 0;

            java.util.HashMap<Integer, Integer> map = new java.util.HashMap<>();

            while (curr != -1) {

                if (map.containsKey(curr)) {
                    int cycleLength = step - map.get(curr);
                    maxCycle = Math.max(maxCycle, cycleLength);
                    break;
                }

                if (visited[curr]) break;

                map.put(curr, step);
                visited[curr] = true;

                step++;
                curr = next[curr];
            }
        }

        return maxCycle;
    }
}