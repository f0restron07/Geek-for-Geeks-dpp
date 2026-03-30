class Solution {
    public int minCost(int[][] a) {
        int n=a.length;
        if(n<=1){
            return 0;
        }
        boolean[] b=new boolean[n];
        PriorityQueue<int[]> c=new PriorityQueue<>((x,y)->x[0]-y[0]);
        c.offer(new int[]{0,0});
        int d=0,e=0;
        while(!c.isEmpty()&&e<n){
            int[] f=c.poll();
            int g=f[0],h=f[1];
            if(b[h]){
                continue;
            }
            b[h]=true;
            d+=g;
            e++;
            for(int i=0;i<n;i++){
                if(!b[i]){
                    int j=Math.abs(a[h][0]-a[i][0])+Math.abs(a[h][1]-a[i][1]);
                    c.offer(new int[]{j,i});
                }
            }
        }
        return d;
    }
}