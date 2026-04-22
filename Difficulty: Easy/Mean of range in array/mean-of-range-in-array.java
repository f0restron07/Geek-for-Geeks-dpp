import java.util.*;

class Solution {

    public ArrayList<Integer> findMean(int[] arr, int[][] queries) {
        
        int n = arr.length;
        
     
        int[] prefix = new int[n];
        prefix[0] = arr[0];
        
        for (int i = 1; i < n; i++) {
            prefix[i] = prefix[i - 1] + arr[i];
        }
        
        ArrayList<Integer> result = new ArrayList<>();
        

        for (int[] q : queries) {
            int l = q[0];
            int r = q[1];
            
            int sum;
            if (l == 0) {
                sum = prefix[r];
            } else {
                sum = prefix[r] - prefix[l - 1];
            }
            
            int length = r - l + 1;
            int mean = sum / length; 
            
            result.add(mean);
        }
        
        return result;
    }
}