class Solution {
    static int t;
    static ArrayList<Integer> articulationPoints(int V, int[][] edges) {
        List<List<Integer>> g = new ArrayList<>();
        for(int i=0;i<V;i++) g.add(new ArrayList<>());
        for(int[] e:edges){g.get(e[0]).add(e[1]);g.get(e[1]).add(e[0]);}
        int[] d=new int[V],l=new int[V];
        boolean[] v=new boolean[V],ap=new boolean[V];
        t=0;
        for(int i=0;i<V;i++) if(!v[i]) dfs(i,-1,g,d,l,v,ap);
        ArrayList<Integer> r=new ArrayList<>();
        for(int i=0;i<V;i++) if(ap[i]) r.add(i);
        if(r.isEmpty()) r.add(-1);
        return r;
    }
    static void dfs(int u,int p,List<List<Integer>> g,int[] d,int[] l,boolean[] v,boolean[] ap){
        v[u]=true;d[u]=l[u]=t++;
        int c=0;
        for(int w:g.get(u)){
            if(!v[w]){
                c++;
                dfs(w,u,g,d,l,v,ap);
                l[u]=Math.min(l[u],l[w]);
                if(p==-1&&c>1) ap[u]=true;
                if(p!=-1&&l[w]>=d[u]) ap[u]=true;
            } else if(w!=p) l[u]=Math.min(l[u],d[w]);
        }
    }
}