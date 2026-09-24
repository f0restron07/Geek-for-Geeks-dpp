class Solution {
  public:
    int tree[1002];
    int MAXH=1000;
    void upd(int i,int v){
        for(;i<=MAXH+1;i+=i&(-i)){
            if(tree[i]<v){
                tree[i]=v;
            }
        }
    }
    int qry(int i){
        int s=0;
        for(;i>0;i-=i&(-i)){
            if(tree[i]>s){
                s=tree[i];
            }
        }
        return s;
    }
    int maxStackHeight(vector<int> &r, vector<int> &h){
        int n=r.size();
        for(int i=0;i<=MAXH+1;i++){
            tree[i]=0;
        }
        vector<int> idx(n);
        for(int i=0;i<n;i++){
            idx[i]=i;
        }
        sort(idx.begin(),idx.end(),[&](int a,int b){
            return r[a]<r[b];
        });
        int best=0;
        int i=0;
        while(i<n){
            int j=i;
            while(j<n&&r[idx[j]]==r[idx[i]]){
                j++;
            }
            vector<pair<int,int>> results;
            for(int t=i;t<j;t++){
                int hi=h[idx[t]];
                int cur=qry(hi-1)+hi;
                results.push_back({hi,cur});
                best=max(best,cur);
            }
            for(auto& [hi,cur]:results){
                upd(hi,cur);
            }
            i=j;
        }
        return best;
    }
};