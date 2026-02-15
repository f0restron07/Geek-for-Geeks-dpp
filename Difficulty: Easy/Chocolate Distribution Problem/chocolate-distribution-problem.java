class Solution {
    public int findMinDiff(ArrayList<Integer> arr, int m) {
        Collections.sort(arr);
        int ans = Integer.MAX_VALUE;
        for(int i=0; i+m-1<arr.size(); i++)
            ans = Math.min(ans, arr.get(i+m-1) - arr.get(i));
        return ans;
    }
}