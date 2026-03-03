class Solution {
    public int totalElements(int[] a){
        HashMap<Integer,Integer> m=new HashMap<>();
        int l=0,res=0;
        for(int r=0;r<a.length;r++){
            m.merge(a[r],1,Integer::sum);
            while(m.size()>2){
                m.merge(a[l],-1,Integer::sum);
                if(m.get(a[l])==0)m.remove(a[l]);
                l++;
            }
            res=Math.max(res,r-l+1);
        }
        return res;
    }
}