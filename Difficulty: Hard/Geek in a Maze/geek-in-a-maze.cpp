class Solution {
  public:
    int numberOfCells(int r,int c,int u,int d,vector<vector<char>>& mat){
        int n=mat.size();
        int m=mat[0].size();
        if(mat[r][c]=='#'){
            return 0;
        }
        vector<vector<int>> bu(n,vector<int>(m,-1));
        vector<vector<int>> bd(n,vector<int>(m,-1));
        vector<vector<char>> seen(n,vector<char>(m,0));
        priority_queue<array<int,5>> pq;
        bu[r][c]=u;
        bd[r][c]=d;
        pq.push({u+d,u,d,r,c});
        int cnt=0;
        int dx[]={0,0,-1,1};
        int dy[]={1,-1,0,0};
        while(!pq.empty()){
            auto t=pq.top();
            pq.pop();
            int ur=t[1];
            int dr=t[2];
            int i=t[3];
            int j=t[4];
            if(ur<bu[i][j]&&dr<bd[i][j]){
                continue;
            }
            if(!seen[i][j]){
                seen[i][j]=1;
                cnt++;
            }
            for(int k=0;k<4;k++){
                int ni=i+dx[k];
                int nj=j+dy[k];
                if(ni<0||ni>=n||nj<0||nj>=m||mat[ni][nj]=='#'){
                    continue;
                }
                int nur=ur;
                int ndr=dr;
                if(k==2){
                    if(ur==0){
                        continue;
                    }
                    nur=ur-1;
                }else if(k==3){
                    if(dr==0){
                        continue;
                    }
                    ndr=dr-1;
                }
                if(nur>bu[ni][nj]||ndr>bd[ni][nj]){
                    bu[ni][nj]=max(bu[ni][nj],nur);
                    bd[ni][nj]=max(bd[ni][nj],ndr);
                    pq.push({bu[ni][nj]+bd[ni][nj],bu[ni][nj],bd[ni][nj],ni,nj});
                }
            }
        }
        return cnt;
    }
};