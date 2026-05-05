class Solution{
    public long sumXOR(int[] a){
        int b=a.length;
        long c=0;
        for(int d=0;d<20;d++){
            long e=0;
            for(int f=0;f<b;f++){
                if((a[f]>>d&1)==1){
                    e++;
                }
            }
            c+=e*(b-e)*(1L<<d);
        }
        return c;
    }
}