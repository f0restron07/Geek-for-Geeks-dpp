class Solution {
    public static ArrayList<Integer> findClosestPair(int arr1[], int arr2[], int x) {
        int a=0,b=arr2.length-1;
        int c=-1,d=-1;
        long e=(long)1e18;
        while(a<arr1.length&&b>=0){
            long f=(long)arr1[a]+arr2[b];
            long g=f>x?f-x:x-f;
            if(g<e){e=g;c=arr1[a];d=arr2[b];}
            if(f<x)a++;
            else b--;
        }
        ArrayList<Integer>h=new ArrayList<>();
        h.add(c);h.add(d);
        return h;
    }
}