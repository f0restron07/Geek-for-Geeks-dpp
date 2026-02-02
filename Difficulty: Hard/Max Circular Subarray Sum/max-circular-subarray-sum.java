class Solution {
    public int maxCircularSum(int arr[]) {
        int n = arr.length;
        int total = 0, maxSum = Integer.MIN_VALUE, minSum = Integer.MAX_VALUE;
        int curMax = 0, curMin = 0;
        
        for (int x : arr) {
            total += x;
            curMax = Math.max(curMax + x, x);
            maxSum = Math.max(maxSum, curMax);
            curMin = Math.min(curMin + x, x);
            minSum = Math.min(minSum, curMin);
        }
        
        // If all negative, wrapping gives empty subarray (invalid)
        return maxSum > 0 ? Math.max(maxSum, total - minSum) : maxSum;
    }
}