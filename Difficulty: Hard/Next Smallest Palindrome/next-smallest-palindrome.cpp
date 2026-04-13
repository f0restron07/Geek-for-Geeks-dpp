class Solution {
public:
    vector<int> nextPalindrome(vector<int>& num) {
        int n=num.size();

        bool all9=true;
        for(int d:num){
            if(d!=9){all9=false;break;}
        }
        if(all9){
            vector<int> res(n+1,0);
            res[0]=res[n]=1;
            return res;
        }
        
        vector<int> res=num;
        
        for(int i=0;i<n/2;i++){
            res[n-1-i]=res[i];
        }
        
        bool isGreater=false;
        for(int i=0;i<n;i++){
            if(res[i]>num[i]){isGreater=true;break;}
            if(res[i]<num[i]){break;}
        }
        
        if(isGreater){return res;}
        
        int i=(n-1)/2;
        int carry=1;
        while(i>=0&&carry){
            res[i]+=carry;
            carry=res[i]/10;
            res[i]%=10;
            res[n-1-i]=res[i];
            i--;
        }
        
        return res;
    }
};