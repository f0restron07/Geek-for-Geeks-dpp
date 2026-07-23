class Solution {
  public:
    bool canRepresentBST(vector<int> &arr) {
        stack<int>s;
        int a=INT_MIN;
        for(int i=0;i<arr.size();i++){
            if(arr[i]<a){
                return false;
            }
            while(!s.empty()&&s.top()<arr[i]){
                a=s.top();
                s.pop();
            }
            s.push(arr[i]);
        }
        return true;
    }
};