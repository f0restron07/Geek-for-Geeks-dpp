class Solution {
    public int maxMinHeight(int[] arr, int k, int w) {
        int lo = Integer.MAX_VALUE, hi = 0;
        for (int x : arr) lo = Math.min(lo, x);
        hi = lo + k; // max possible min height

        while (lo < hi) {
            int mid = lo + (hi - lo + 1) / 2;
            if (canAchieve(arr, k, w, mid)) lo = mid;
            else hi = mid - 1;
        }
        return lo;
    }

    boolean canAchieve(int[] arr, int k, int w, int target) {
        int n = arr.length;
        long days = 0;
        long[] extra = new long[n + 1]; // difference array for added water
        long cur = 0;

        for (int i = 0; i < n; i++) {
            cur += extra[i];
            long need = target - (arr[i] + cur);
            if (need > 0) {
                days += need;
                if (days > k) return false;
                cur += need;
                if (i + w < n) extra[i + w] -= need; // window ends
            }
        }
        return days <= k;
    }
}