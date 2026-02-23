class Solution {
    public static ArrayList<Integer> findUnion(int[] a, int[] b) {
        Set<Integer> s = new HashSet<>();
        for(int x:a) s.add(x);
        for(int x:b) s.add(x);
        return new ArrayList<>(s);
    }
}