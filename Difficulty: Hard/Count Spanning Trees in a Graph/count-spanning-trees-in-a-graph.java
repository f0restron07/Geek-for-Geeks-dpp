class Solution{
    public int countSpanTree(int n,int[][] edges){
        if(n==1){
            return 1;
        }
        int a=n-1;
        long[][] b=new long[a][a];
        for(int[] c:edges){
            int d=c[0];
            int e=c[1];
            if(d<a){
                b[d][d]++;
            }
            if(e<a){
                b[e][e]++;
            }
            if(d<a&&e<a){
                b[d][e]--;
                b[e][d]--;
            }
        }
        long f=1;
        int g=1;
        for(int i=0;i<a;i++){
            int h=-1;
            for(int j=i;j<a;j++){
                if(b[j][i]!=0){
                    h=j;
                    break;
                }
            }
            if(h==-1){
                return 0;
            }
            if(h!=i){
                long[] l=b[i];
                b[i]=b[h];
                b[h]=l;
                g=-g;
            }
            for(int j=i+1;j<a;j++){
                for(int k=i+1;k<a;k++){
                    b[j][k]=(b[j][k]*b[i][i]-b[j][i]*b[i][k])/f;
                }
            }
            f=b[i][i];
        }
        return (int)(g*b[a-1][a-1]);
    }
}