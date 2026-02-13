class Solution {
    public int minTime(int[] arr, int k) {
        int lo = 0, hi = 0;
        for (int x : arr) { lo = Math.max(lo, x); hi += x; }
        while (lo < hi) {
            int mid = lo + (hi - lo) / 2;
            if (canPaint(arr, k, mid)) hi = mid;
            else lo = mid + 1;
        }
        return lo;
    }
    
    boolean canPaint(int[] arr, int k, int maxTime) {
        int painters = 1, sum = 0;
        for (int x : arr) {
            if (sum + x > maxTime) { painters++; sum = x; }
            else sum += x;
        }
        return painters <= k;
    }
}