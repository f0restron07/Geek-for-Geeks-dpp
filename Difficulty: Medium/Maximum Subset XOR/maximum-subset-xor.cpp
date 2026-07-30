class Solution {
  public:
    int maxSubsetXOR(vector<int> &arr){
        int B=20;
        vector<int> basis(B+1,0);
        for(int x:arr){
            for(int b=B;b>=0;b--){
                if(!((x>>b)&1)){
                    continue;
                }
                if(!basis[b]){
                    basis[b]=x;
                    break;
                }
                x^=basis[b];
            }
        }
        int res=0;
        for(int b=B;b>=0;b--){
            if((res^basis[b])>res){
                res=res^basis[b];
            }
        }
        return res;
    }
};