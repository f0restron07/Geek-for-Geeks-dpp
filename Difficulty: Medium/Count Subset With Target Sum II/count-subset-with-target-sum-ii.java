class Solution {
    public int countSubset(int[] arr, int k) {
        int n = arr.length;
        int mid = n / 2;
        
        Map<Integer, Integer> leftSums = getAllSums(arr, 0, mid);
        Map<Integer, Integer> rightSums = getAllSums(arr, mid, n);
        
        int count = 0;
        for (Map.Entry<Integer, Integer> entry : leftSums.entrySet()) {
            int needed = k - entry.getKey();
            count += entry.getValue() * rightSums.getOrDefault(needed, 0);
        }
        
        return count;
    }
    
    private Map<Integer, Integer> getAllSums(int[] arr, int start, int end) {
        Map<Integer, Integer> sums = new HashMap<>();
        int size = end - start;
        int total = 1 << size; 
        
        for (int mask = 0; mask < total; mask++) {
            int sum = 0;
            for (int i = 0; i < size; i++) {
                if ((mask & (1 << i)) != 0) {
                    sum += arr[start + i];
                }
            }
            sums.put(sum, sums.getOrDefault(sum, 0) + 1);
        }
        
        return sums;
    }
}