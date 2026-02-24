class Solution {
    public int equalSumSpan(int[] a1, int[] a2) {
        int n = a1.length;
        HashMap<Integer, Integer> map = new HashMap<>();
        map.put(0, -1);
        int prefix = 0, ans = 0;
        for (int i = 0; i < n; i++) {
            prefix += a1[i] - a2[i];
            if (map.containsKey(prefix))
                ans = Math.max(ans, i - map.get(prefix));
            else
                map.put(prefix, i);
        }
        return ans;
    }
}