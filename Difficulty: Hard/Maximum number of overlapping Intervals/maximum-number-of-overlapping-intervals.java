class Solution {
    public static int overlapInt(int[][] arr) {
        List<int[]> events = new ArrayList<>();
        for (int[] a : arr) {
            events.add(new int[]{a[0], 1});
            events.add(new int[]{a[1] + 1, -1});
        }
        events.sort((a, b) -> a[0] != b[0] ? a[0] - b[0] : a[1] - b[1]);
        int cur = 0, max = 0;
        for (int[] e : events) {
            cur += e[1];
            max = Math.max(max, cur);
        }
        return max;
    }
}