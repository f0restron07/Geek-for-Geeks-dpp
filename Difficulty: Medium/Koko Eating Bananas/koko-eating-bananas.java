class Solution {
    public int kokoEat(int[] arr, int k) {
        int lo = 1, hi = 0;
        for (int a : arr) hi = Math.max(hi, a);
        while (lo < hi) {
            int mid = lo + (hi - lo) / 2, h = 0;
            for (int a : arr) h += (a + mid - 1) / mid;
            if (h <= k) hi = mid;
            else lo = mid + 1;
        }
        return lo;
    }
}