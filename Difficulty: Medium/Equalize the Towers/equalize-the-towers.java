class Solution {
    public int minCost(int[] heights, int[] cost) {
        int lo = Integer.MAX_VALUE, hi = 0;
        for (int h : heights) { lo = Math.min(lo, h); hi = Math.max(hi, h); }
        
        while (hi - lo > 2) {
            int m1 = lo + (hi - lo) / 3;
            int m2 = hi - (hi - lo) / 3;
            if (calc(heights, cost, m1) < calc(heights, cost, m2)) hi = m2;
            else lo = m1;
        }
        
        long ans = Long.MAX_VALUE;
        for (int h = lo; h <= hi; h++) ans = Math.min(ans, calc(heights, cost, h));
        return (int) ans;
    }
    
    long calc(int[] h, int[] c, int t) {
        long s = 0;
        for (int i = 0; i < h.length; i++) s += (long) Math.abs(h[i] - t) * c[i];
        return s;
    }
}