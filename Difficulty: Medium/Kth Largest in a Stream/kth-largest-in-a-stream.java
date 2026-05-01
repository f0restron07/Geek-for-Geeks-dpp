class Solution {
    static ArrayList<Integer> kthLargest(int[] arr, int k) {
        ArrayList<Integer> r=new ArrayList<>();
        PriorityQueue<Integer> pq=new PriorityQueue<>();
        for(int i=0;i<arr.length;i++){
            pq.offer(arr[i]);
            if(pq.size()>k) pq.poll();
            r.add(pq.size()<k?-1:pq.peek());
        }
        return r;
    }
}