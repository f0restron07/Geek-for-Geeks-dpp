class Solution {
  public:
    vector<int> makeBeautiful(vector<int> arr) {
        vector<int> a;
        for(int i=0;i<(int)arr.size();i++){
            if(!a.empty()&&(a.back()<0)!=(arr[i]<0)){
                a.pop_back();
            }else{
                a.push_back(arr[i]);
            }
        }
        return a;
    }
};