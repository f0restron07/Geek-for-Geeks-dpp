class Solution {
    public ArrayList<Integer> missingRange(int[] arr, int low, int high) {
        boolean[] present = new boolean[100001];
        for (int x : arr) present[x] = true;
        ArrayList<Integer> res = new ArrayList<>();
        for (int i = low; i <= high; i++)
            if (!present[i]) res.add(i);
        return res;
    }
}