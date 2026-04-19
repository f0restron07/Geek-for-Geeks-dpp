class Solution{
    public boolean isPower(int x,int y){
        if(y==1)return true;
        if(x<=1)return x==1&&y==1;
        long p=1;
        while(p<y)p*=x;
        return p==y;
    }
}