class Solution {
    static ArrayList<Integer> diagView(int mat[][]) {
        int n=mat.length;
        ArrayList<Integer> res=new ArrayList<>();
        
        for(int j=0;j<n;j++){
            int r=0,c=j;
            while(r<n&&c>=0){
                res.add(mat[r][c]);
                r++;
                c--;
            }
        }
       
        for(int i=1;i<n;i++){
            int r=i,c=n-1;
            while(r<n&&c>=0){
                res.add(mat[r][c]);
                r++;
                c--;
            }
        }
        
        return res;
    }
}