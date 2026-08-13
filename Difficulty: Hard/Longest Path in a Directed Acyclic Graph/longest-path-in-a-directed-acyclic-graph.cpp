class Solution {
  public:
    vector<int> maxDistance(int V, int src, vector<vector<int>> &edges){
        vector<vector<pair<int,int>>> adj(V);
        vector<int> indeg(V,0);
        for(auto& e:edges){
            adj[e[0]].push_back({e[1],e[2]});
            indeg[e[1]]++;
        }
        queue<int> q;
        for(int i=0;i<V;i++){
            if(indeg[i]==0){
                q.push(i);
            }
        }
        vector<int> topo;
        while(!q.empty()){
            int u=q.front();
            q.pop();
            topo.push_back(u);
            for(auto& [v,w]:adj[u]){
                if(--indeg[v]==0){
                    q.push(v);
                }
            }
        }
        vector<long long> dist(V,LLONG_MIN);
        dist[src]=0;
        for(int u:topo){
            if(dist[u]==LLONG_MIN){
                continue;
            }
            for(auto& [v,w]:adj[u]){
                if(dist[u]+w>dist[v]){
                    dist[v]=dist[u]+w;
                }
            }
        }
        vector<int> res(V);
        for(int i=0;i<V;i++){
            res[i]=(dist[i]==LLONG_MIN)?INT_MIN:(int)dist[i];
        }
        return res;
    }
};