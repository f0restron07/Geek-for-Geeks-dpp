class Solution {
  public:
    vector<int> find3Numbers(vector<int> &arr) {
        int n=arr.size();
        if(n<3)return {};
        vector<int> l(n);
        l[0]=-1;
        int m=0;
        for(int i=1;i<n;i++){
            if(arr[i]>arr[m])l[i]=m;
            else{l[i]=-1;if(arr[i]<arr[m])m=i;}
        }
        int x=n-1;
        for(int i=n-2;i>=0;i--){
            if(arr[i]<arr[x]&&l[i]!=-1)return {arr[l[i]],arr[i],arr[x]};
            if(arr[i]>arr[x])x=i;
        }
        return {};
    }
};