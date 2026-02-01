class Solution {
    public ArrayList<Integer> maxOfSubarrays(int[] a, int k) {
        ArrayList<Integer> r = new ArrayList<>();
        Deque<Integer> d = new ArrayDeque<>();
        for(int i = 0; i < a.length; i++) {
            if(!d.isEmpty() && d.peekFirst() <= i - k) d.pollFirst();
            while(!d.isEmpty() && a[d.peekLast()] <= a[i]) d.pollLast();
            d.addLast(i);
            if(i >= k - 1) r.add(a[d.peekFirst()]);
        }
        return r;
    }
}