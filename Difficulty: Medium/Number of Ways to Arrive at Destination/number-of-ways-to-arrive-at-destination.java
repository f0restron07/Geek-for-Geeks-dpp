import java.util.*;

class Solution {
    public int countPaths(int V, int[][] edges) {
        int mod = (int)(1e9 + 7);
        
        List<List<int[]>> adj = new ArrayList<>();
        for (int i = 0; i < V; i++) {
            adj.add(new ArrayList<>());
        }
        for (int[] edge : edges) {
            adj.get(edge[0]).add(new int[]{edge[1], edge[2]});
            adj.get(edge[1]).add(new int[]{edge[0], edge[2]});
        }
        
        long[] dist = new long[V]; 
        Arrays.fill(dist, Long.MAX_VALUE);
        dist[0] = 0;
        
        int[] ways = new int[V];
        ways[0] = 1;
        
        PriorityQueue<long[]> pq = new PriorityQueue<>((a, b) -> Long.compare(a[0], b[0]));
        pq.offer(new long[]{0, 0});
        
        while (!pq.isEmpty()) {
            long[] curr = pq.poll();
            long currentDist = curr[0];
            int u = (int) curr[1];
            
            if (currentDist > dist[u]) continue;
            
            for (int[] neighbor : adj.get(u)) {
                int v = neighbor[0];
                long time = neighbor[1];
                
                if (currentDist + time < dist[v]) {
                    dist[v] = currentDist + time;
                    ways[v] = ways[u];
                    pq.offer(new long[]{dist[v], v});
                } else if (currentDist + time == dist[v]) {
                    ways[v] = (ways[v] + ways[u]) % mod;
                }
            }
        }
        
        return ways[V - 1];
    }
}