class Solution {
    int maxOnes(int[] arr) {
        int n=arr.length,total=0;
        for(int x:arr) total+=x;
        
        int maxGain=0,cur=0;
        for(int i=0;i<n;i++){
            cur+=(arr[i]==0?1:-1);
            if(cur<0) cur=0;
            if(cur>maxGain) maxGain=cur;
        }
        return total+maxGain;
    }
}