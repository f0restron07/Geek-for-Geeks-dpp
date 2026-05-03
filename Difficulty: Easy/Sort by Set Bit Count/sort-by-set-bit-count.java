class Solution {
    ArrayList<Integer> sortBySetBitCount(int[] arr) {
        Integer[] a=new Integer[arr.length];
        for(int i=0;i<arr.length;i++) a[i]=arr[i];
        Arrays.sort(a,(x,y)->Integer.bitCount(y)-Integer.bitCount(x));
        ArrayList<Integer> res=new ArrayList<>(Arrays.asList(a));
        return res;
    }
}