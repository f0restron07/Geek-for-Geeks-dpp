class Solution {
    public int visibleBuildings(int arr[]) {
        int count=1, mx=arr[0];
        for(int i=1;i<arr.length;i++){
            if(arr[i]>=mx){
                mx=arr[i];
                count++;
            }
        }
        return count;
    }
}