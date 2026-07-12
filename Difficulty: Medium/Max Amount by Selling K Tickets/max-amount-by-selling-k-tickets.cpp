class Solution {
  public:
    int maxAmount(vector<int>& arr, int k) {
        const long long M=1000000007;
        priority_queue<int> pq(arr.begin(),arr.end());
        long long s=0;
        while(k>0&&!pq.empty()){
            int t=pq.top();
            pq.pop();
            if(t<=0){
                break;
            }
            s=(s+t)%M;
            if(t-1>0){
                pq.push(t-1);
            }
            k--;
        }
        return (int)s;
    }
};