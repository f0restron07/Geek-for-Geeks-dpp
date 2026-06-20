class Solution {
  public:
    int getLastDigit(string& a, string& b) {
        if(b=="0"){return 1;}
        int d=a.back()-'0';
        int r=0;
        for(char c:b){r=(r*10+(c-'0'))%4;}
        int e=(r==0)?4:r;
        int x=1;
        for(int i=0;i<e;i++){x=(x*d)%10;}
        return x;
    }
};