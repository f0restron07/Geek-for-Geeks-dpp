class Solution {
    public int hIndex(int[] citations) {
        Arrays.sort(citations);
        int n = citations.length, h = 0;
        for (int i = 0; i < n; i++) {
            int papersLeft = n - i;
            if (citations[i] >= papersLeft) {
                h = Math.max(h, papersLeft);
                break;
            }
        }
        return h;
    }
}