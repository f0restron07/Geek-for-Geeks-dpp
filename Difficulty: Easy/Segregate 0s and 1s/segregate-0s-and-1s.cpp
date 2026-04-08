class Solution {
  public:
    void segregate0and1(vector<int> &arr) {
        int i=0,j=arr.size()-1;
        while(i<j){
            while(i<j&&arr[i]==0)i++;
            while(i<j&&arr[j]==1)j--;
            if(i<j){
                arr[i]=0;
                arr[j]=1;
                i++;
                j--;
            }
        }
    }
};