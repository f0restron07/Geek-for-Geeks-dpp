class Solution {
    int maxProduct(int[] a) {
        int mx = a[0], mn = a[0], r = a[0];

        for (int i = 1; i < a.length; i++) {
            if (a[i] < 0) {
                int t = mx;
                mx = mn;
                mn = t;
            }
            mx = Math.max(a[i], mx * a[i]);
            mn = Math.min(a[i], mn * a[i]);
            r = Math.max(r, mx);
        }

        return r;
    }
}