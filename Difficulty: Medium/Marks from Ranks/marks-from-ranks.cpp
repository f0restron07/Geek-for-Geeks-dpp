class Solution {
  public:
    vector<int> getMarks(vector<int> &l, vector<int> &r, vector<int> &rank){
        int k=l.size();
        vector<long long> cum(k);
        long long run=0;
        for(int i=0;i<k;i++){
            run+=(r[i]-l[i]+1);
            cum[i]=run;
        }
        vector<int> res;
        for(int q:rank){
            int lo=0;
            int hi=k-1;
            int idx=k-1;
            while(lo<=hi){
                int mid=(lo+hi)/2;
                if(cum[mid]>=q){
                    idx=mid;
                    hi=mid-1;
                }else{
                    lo=mid+1;
                }
            }
            long long before=(idx==0)?0:cum[idx-1];
            int mark=l[idx]+(q-before-1);
            res.push_back(mark);
        }
        return res;
    }
};