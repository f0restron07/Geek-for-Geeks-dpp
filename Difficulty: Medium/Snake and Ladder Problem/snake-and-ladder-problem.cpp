class Solution {
  public:
    int minThrows(int n, vector<int>& lad, vector<int>& sn){
        int N=n*n;
        vector<int> jump(N+1);
        for(int i=1;i<=N;i++){
            jump[i]=i;
        }
        for(int i=0;i<(int)lad.size();i+=2){
            jump[lad[i]]=lad[i+1];
        }
        for(int i=0;i<(int)sn.size();i+=2){
            jump[sn[i]]=sn[i+1];
        }
        vector<int> dist(N+1,-1);
        queue<int> q;
        q.push(1);
        dist[1]=0;
        while(!q.empty()){
            int u=q.front();
            q.pop();
            if(u==N){
                return dist[u];
            }
            for(int d=1;d<=6;d++){
                int v=u+d;
                if(v>N){
                    break;
                }
                v=jump[v];
                if(dist[v]==-1){
                    dist[v]=dist[u]+1;
                    q.push(v);
                }
            }
        }
        return -1;
    }
};