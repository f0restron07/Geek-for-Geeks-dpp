class Solution {
  public:
    int countMinOperations(vector<int>& arr){
        long long inc=0;
        int maxDoubles=0;
        for(int x:arr){
            int bits=0;
            int highest=0;
            int v=x;
            int pos=0;
            while(v>0){
                if(v&1){
                    bits++;
                    highest=pos;
                }
                v>>=1;
                pos++;
            }
            inc+=bits;
            maxDoubles=max(maxDoubles,highest);
        }
        return (int)(inc+maxDoubles);
    }
};