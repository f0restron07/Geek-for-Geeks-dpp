class Solution{
    public int minSteps(int m,int n,int d){
        if(d==0){return 0;}
        if(d>Math.max(m,n)){return -1;}
        int a=g(m,n);
        if(d%a!=0){return -1;}
        int b=f(m,n,d);
        int c=f(n,m,d);
        return Math.min(b,c);
    }
    int g(int a,int b){
        while(b!=0){
            int c=a%b;
            a=b;
            b=c;
        }
        return a;
    }
    int f(int a,int b,int d){
        int c=0,e=0,s=0;
        while(c!=d&&e!=d){
            if(c==0){
                c=a;
                s++;
            }else if(e==b){
                e=0;
                s++;
            }else{
                int p=Math.min(c,b-e);
                c-=p;
                e+=p;
                s++;
            }
        }
        return s;
    }
}