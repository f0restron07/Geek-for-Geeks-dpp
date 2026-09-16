class Solution {
  public:
    int dominantPairs(vector<int> &arr){
        int n=arr.size();
        int h=n/2;
        vector<int> second(arr.begin()+h,arr.end());
        sort(second.begin(),second.end());
        long long cnt=0;
        for(int i=0;i<h;i++){
            int thr=(int)floor(arr[i]/5.0);
            int c=upper_bound(second.begin(),second.end(),thr)-second.begin();
            cnt+=c;
        }
        return (int)cnt;
    }
};