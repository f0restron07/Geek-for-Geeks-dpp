class Solution {
    public int findMotherVertex(int V, int[][] edges) {
        List<List<Integer>> a=new ArrayList<>();
        List<List<Integer>> b=new ArrayList<>();
        for(int i=0;i<V;i++){
            a.add(new ArrayList<>());
            b.add(new ArrayList<>());
        }
        for(int[] e:edges){
            a.get(e[0]).add(e[1]);
            b.get(e[1]).add(e[0]);
        }
        boolean[] c=new boolean[V];
        int[] d=new int[V];
        int f=0;
        for(int i=0;i<V;i++){
            if(!c[i]){
                Deque<int[]> g=new ArrayDeque<>();
                g.push(new int[]{i,0});
                c[i]=true;
                while(!g.isEmpty()){
                    int[] h=g.peek();
                    int u=h[0];
                    List<Integer> p=a.get(u);
                    if(h[1]<p.size()){
                        int v=p.get(h[1]);
                        h[1]++;
                        if(!c[v]){
                            c[v]=true;
                            g.push(new int[]{v,0});
                        }
                    }else{
                        d[f++]=u;
                        g.pop();
                    }
                }
            }
        }
        int j=d[V-1];
        boolean[] k=new boolean[V];
        Deque<Integer> q=new ArrayDeque<>();
        q.offer(j);
        k[j]=true;
        int m=1;
        while(!q.isEmpty()){
            int u=q.poll();
            for(int v:a.get(u)){
                if(!k[v]){
                    k[v]=true;
                    m++;
                    q.offer(v);
                }
            }
        }
        if(m<V){
            return -1;
        }
        boolean[] n=new boolean[V];
        q.offer(j);
        n[j]=true;
        int r=j;
        while(!q.isEmpty()){
            int u=q.poll();
            if(u<r){
                r=u;
            }
            for(int v:b.get(u)){
                if(!n[v]){
                    n[v]=true;
                    q.offer(v);
                }
            }
        }
        return r;
    }
}