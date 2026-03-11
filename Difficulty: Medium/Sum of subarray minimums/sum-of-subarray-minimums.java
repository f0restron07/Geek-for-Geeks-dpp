class Solution {
    public int sumSubMins(int[] arr) {
        int n=arr.length;
        int[] left=new int[n];
        int[] right=new int[n];
        Deque<Integer> st=new ArrayDeque<>();
        for(int i=0;i<n;i++){
            while(!st.isEmpty()&&arr[st.peek()]>=arr[i]){
                st.pop();
            }
            left[i]=st.isEmpty()?-1:st.peek();
            st.push(i);
        }
        st.clear();
        for(int i=n-1;i>=0;i--){
            while(!st.isEmpty()&&arr[st.peek()]>arr[i]){
                st.pop();
            }
            right[i]=st.isEmpty()?n:st.peek();
            st.push(i);
        }
        int sum=0;
        for(int i=0;i<n;i++){
            sum+=arr[i]*(i-left[i])*(right[i]-i);
        }
        return sum;
    }
}