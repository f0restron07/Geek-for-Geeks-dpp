class Solution {
  public:
    vector<int> p;
    int find(int x){
        while(p[x]!=x){
            p[x]=p[p[x]];
            x=p[x];
        }
        return x;
    }
    int minEdgesReq(int n, vector<vector<int>>& edges){
        int m=edges.size();
        if(m<n-1){
            return -1;
        }
        p.resize(n);
        for(int i=0;i<n;i++){
            p[i]=i;
        }
        int c=n;
        for(auto& e:edges){
            int a=find(e[0]);
            int b=find(e[1]);
            if(a!=b){
                p[a]=b;
                c--;
            }
        }
        return c-1;
    }
};