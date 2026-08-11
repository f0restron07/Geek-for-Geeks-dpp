class Solution {
  public:
    vector<int> largestSquare(vector<vector<int>>& mat, vector<vector<int>>& queries, int k){
        int n=mat.size();
        int m=mat[0].size();
        vector<vector<int>> p(n+1,vector<int>(m+1,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                p[i+1][j+1]=p[i][j+1]+p[i+1][j]-p[i][j]+mat[i][j];
            }
        }
        auto ones=[&](int r1,int c1,int r2,int c2)->int{
            return p[r2+1][c2+1]-p[r1][c2+1]-p[r2+1][c1]+p[r1][c1];
        };
        vector<int> res;
        for(auto& q:queries){
            int i=q[0];
            int j=q[1];
            int maxR=min(min(i,j),min(n-1-i,m-1-j));
            int lo=0;
            int hi=maxR;
            int ans=-1;
            while(lo<=hi){
                int mid=(lo+hi)/2;
                int c=ones(i-mid,j-mid,i+mid,j+mid);
                if(c<=k){
                    ans=mid;
                    lo=mid+1;
                }else{
                    hi=mid-1;
                }
            }
            res.push_back(ans==-1?-1:2*ans+1);
        }
        return res;
    }
};