class Solution{
    public ArrayList<Integer>countBSTs(int[]a){
        int n=a.length;
        int[]c={1,1,2,5,14,42,132};
        ArrayList<Integer>r=new ArrayList<>();
        for(int i=0;i<n;i++){
            int l=0;
            for(int j=0;j<n;j++){
                if(a[j]<a[i])l++;
            }
            r.add(c[l]*c[n+~i-l+i]);
        }
        return r;
    }
}