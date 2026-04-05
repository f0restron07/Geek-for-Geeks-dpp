class Solution{
    public int totalWays(int[] arr,int target){
        int s=0;
        for(int x:arr)s+=x;
        if(target>s||target<-s||((s+target)&1)==1)return 0;
        int p=(s+target)/2;
        int[] d=new int[p+1];
        d[0]=1;
        for(int x:arr){
            for(int j=p;j>=x;j--){
                d[j]+=d[j-x];
            }
        }
        return d[p];
    }
}