class Solution {
    int maxSum(int[] arr) {
        int n = arr.length, s = 0, c = 0;
        for (
            int i = 0; i < n; i++
            ) { s += arr[i]; c += i * arr[i]; }
        int m = c;
        for (int i = 1; i < n; i++) { c += s - n * arr[n - i]; m = Math.max(m, c); }
        return m;
    }
}