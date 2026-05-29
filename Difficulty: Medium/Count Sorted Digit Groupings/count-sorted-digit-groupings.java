class Solution {
    public int validGroups(String s) {
        int a=s.length();
        int[]b=new int[a];
        for(int i=0;i<a;i++) b[i]=s.charAt(i)-'0';
        int[][]c=new int[a][a];
        for(int i=0;i<a;i++){
            c[i][i]=b[i];
            for(int j=i+1;j<a;j++) c[i][j]=c[i][j-1]+b[j];
        }
        int[][]d=new int[a+1][901];
        for(int[]e:d) java.util.Arrays.fill(e,-1);
        return f(0,0,a,c,d);
    }
    int f(int g,int h,int a,int[][]c,int[][]d){
        if(g==a) return 1;
        if(d[g][h]!=-1) return d[g][h];
        int e=0;
        for(int i=g;i<a;i++){
            if(c[g][i]>=h) e+=f(i+1,c[g][i],a,c,d);
        }
        return d[g][h]=e;
    }
}