class Solution{
    public ArrayList<Integer> commonElements(int[] a,int[] b,int[] c){
        ArrayList<Integer> d=new ArrayList<>();
        int i=0,j=0,k=0;
        while(i<a.length&&j<b.length&&k<c.length){
            if(a[i]==b[j]&&b[j]==c[k]){
                if(d.isEmpty()||d.get(d.size()-1)!=a[i]){d.add(a[i]);}
                i++;j++;k++;
            }else if(a[i]<b[j]){i++;}
            else if(b[j]<c[k]){j++;}
            else{k++;}
        }
        return d;
    }
}