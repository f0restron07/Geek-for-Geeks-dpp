class Solution {
    public int longestSubarray(int[] arr, int k) {
        int n = arr.length;
        int[] prefix = new int[n + 1];
        prefix[0] = 0;
        for (int i = 0; i < n; i++) {
            prefix[i + 1] = prefix[i] + (arr[i] > k ? 1 : -1);
        }
        HashMap<Integer, Integer> firstOccurrence = new HashMap<>();
        ArrayList<Integer> stack = new ArrayList<>();
        for (int i = 0; i <= n; i++) {
            if (stack.isEmpty() || prefix[i] < prefix[stack.get(stack.size() - 1)]) {
                stack.add(i);
            }
        }
        int ans = 0;
        for (int i = n; i >= 1; i--) {
            while (!stack.isEmpty() && prefix[stack.get(stack.size() - 1)] < prefix[i]) {
                ans = Math.max(ans, i - stack.get(stack.size() - 1));
                stack.remove(stack.size() - 1);
            }
        }
        
        return ans;
    }
}