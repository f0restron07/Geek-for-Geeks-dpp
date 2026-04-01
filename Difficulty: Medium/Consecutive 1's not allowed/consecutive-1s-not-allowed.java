class Solution {
    int countStrings(int n) {
        int a=1,b=1;
        for(int i=2;i<=n;i++){
            int c=a+b;
            int d=a;
            a=c;
            b=d;
        }
        return a+b;
    }
}