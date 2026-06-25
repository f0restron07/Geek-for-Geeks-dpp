class Solution {
  public:
    vector<int> ans;
    int len;
    void build(int start,int count,int cur){
        if(count==len){
            ans.push_back(cur);
            return;
        }
        for(int d=start;d<=9;d++){
            build(d+1,count+1,cur*10+d);
        }
    }
    vector<int> increasingNumbers(int n){
        if(n==1){
            return {0,1,2,3,4,5,6,7,8,9};
        }
        if(n>9){
            return {};
        }
        len=n;
        build(1,0,0);
        return ans;
    }
};