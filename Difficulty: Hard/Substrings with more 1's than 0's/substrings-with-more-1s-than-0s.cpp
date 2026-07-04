class Solution {
  public:
    vector<int> bit;
    int sz;
    void upd(int i){
        for(;i<=sz;i+=i&(-i)){
            bit[i]++;
        }
    }
    int qry(int i){
        int s=0;
        for(;i>0;i-=i&(-i)){
            s+=bit[i];
        }
        return s;
    }
    int countSubstring(string& s){
        int n=s.size();
        sz=2*n+2;
        bit.assign(sz+1,0);
        long long ans=0;
        int pre=0;
        upd(pre+n+1);
        for(int j=0;j<n;j++){
            pre+=(s[j]=='1')?1:-1;
            int cur=pre+n+1;
            ans+=qry(cur-1);
            upd(cur);
        }
        return (int)ans;
    }
};