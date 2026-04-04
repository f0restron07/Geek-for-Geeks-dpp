class Solution {
    public ArrayList<String> graycode(int n) {
        ArrayList<String> a=new ArrayList<>();
        int b=1<<n;
        for(int i=0;i<b;i++){
            int c=i^(i>>1);
            StringBuilder d=new StringBuilder();
            for(int j=n-1;j>=0;j--){
                d.append((c>>j)&1);
            }
            a.add(d.toString());
        }
        return a;
    }
}