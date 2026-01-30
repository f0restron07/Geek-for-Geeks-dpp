class Solution {
    public void rearrangeQueue(Queue<Integer> q) {
        int n=q.size(),h=n/2;
        Queue<Integer> f=new LinkedList<>();
        for(int i=0;i<h;i++)f.add(q.poll());
        for(int i=0;i<h;i++){
            q.add(f.poll());q.add(q.poll());
        }
    }
}