class Solution {
  public:
    int minDeletions(vector<int>& arr){
        int n=arr.size();
        vector<int> t;
        for(int x:arr){
            auto p=lower_bound(t.begin(),t.end(),x);
            if(p==t.end()){
                t.push_back(x);
            }else{
                *p=x;
            }
        }
        return n-(int)t.size();
    }
};