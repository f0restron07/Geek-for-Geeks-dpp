class Solution {
  public:
    string chooseSwap(string &s) {
        int n=s.size();
        vector<int> first(26,-1);
        for(int i=0;i<n;i++){
            if(first[s[i]-'a']==-1){
                first[s[i]-'a']=i;
            }
        }
        char a=0;
        char b=0;
        int found=0;
        for(int i=0;i<n&&!found;i++){
            int x=s[i]-'a';
            for(int j=0;j<x;j++){
                if(first[j]>i){
                    a=s[i];
                    b='a'+j;
                    found=1;
                    break;
                }
            }
        }
        if(!found){
            return s;
        }
        for(int i=0;i<n;i++){
            if(s[i]==a){
                s[i]=b;
            }else if(s[i]==b){
                s[i]=a;
            }
        }
        return s;
    }
};