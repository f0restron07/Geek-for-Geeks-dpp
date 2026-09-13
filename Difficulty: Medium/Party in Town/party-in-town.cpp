class Solution {
  public:
    pair<int,int> bfs(int src,vector<vector<int>>& adj,int n){
        vector<int> dist(n+1,-1);
        queue<int> q;
        q.push(src);
        dist[src]=0;
        int far=src;
        while(!q.empty()){
            int u=q.front();
            q.pop();
            for(int v:adj[u-1]){
                if(dist[v]==-1){
                    dist[v]=dist[u]+1;
                    if(dist[v]>dist[far]){
                        far=v;
                    }
                    q.push(v);
                }
            }
        }
        return {far,dist[far]};
    }
    int partyHouse(vector<vector<int>> &adj){
        int n=adj.size();
        if(n==1){
            return 0;
        }
        auto [u,d1]=bfs(1,adj,n);
        auto [v,diam]=bfs(u,adj,n);
        return (diam+1)/2;
    }
};