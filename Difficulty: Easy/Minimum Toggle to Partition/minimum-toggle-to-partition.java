class Solution{
    int minToggle(int[] a){
        int n=a.length;
        int b=0;
        for(int i=0;i<n;i++){
            if(a[i]==1){
                b++;
            }
        }
        int c=0;
        int d=n-b;
        int e=c+d;
        for(int i=0;i<n;i++){
            if(a[i]==1){
                c++;
            }else{
                d--;
            }
            if(c+d<e){
                e=c+d;
            }
        }
        return e;
    }
}