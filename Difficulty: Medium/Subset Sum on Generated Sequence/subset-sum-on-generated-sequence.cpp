class Solution {
  public:
    bool isPossible(vector<int>& arr, int s, int x){
        vector<long long> vals;
        long long total=s;
        if(s<=x){
            vals.push_back(s);
        }
        for(int a:arr){
            long long nxt=total+a;
            if(nxt<=x){
                vals.push_back(nxt);
            }
            total+=nxt;
            if(total>(long long)x*2&&nxt>x){
                break;
            }
        }
        unordered_set<long long> reach;
        reach.insert(0);
        for(long long v:vals){
            vector<long long> add;
            for(long long r:reach){
                if(r+v<=x){
                    add.push_back(r+v);
                }
            }
            for(long long r:add){
                reach.insert(r);
            }
        }
        return reach.count(x)>0;
    }
};