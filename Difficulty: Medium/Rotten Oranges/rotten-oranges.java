class Solution{
    public int orangesRot(int[][]a){
        int m=a.length,n=a[0].length,f=0,t=0;
        Queue<int[]>q=new LinkedList<>();
        for(int i=0;i<m;i++)for(int j=0;j<n;j++){
            if(a[i][j]==2)q.add(new int[]{i,j});
            if(a[i][j]==1)f++;
        }
        if(f==0)return 0;
        int[][]d={{1,0},{-1,0},{0,1},{0,-1}};
        while(!q.isEmpty()){
            int s=q.size();
            for(int k=0;k<s;k++){
                int[]c=q.poll();
                for(int[]di:d){
                    int x=c[0]+di[0],y=c[1]+di[1];
                    if(x>=0&&x<m&&y>=0&&y<n&&a[x][y]==1){
                        a[x][y]=2;
                        f--;
                        q.add(new int[]{x,y});
                    }
                }
            }
            t++;
        }
        return f==0?t-1:-1;
    }
}