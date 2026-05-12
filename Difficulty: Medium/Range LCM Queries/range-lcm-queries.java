class Solution {
    long[] a;
    int b;

    long g(long c,long d){
        while(d!=0){
            long e=d;
            d=c%d;
            c=e;
        }
        return c;
    }

    long l(long c,long d){
        return c/g(c,d)*d;
    }

    void p(int[] c,int d,int e,int f){
        if(e==f){
            a[d]=c[e];
            return;
        }
        int h=(e+f)>>1;
        p(c,d*2+1,e,h);
        p(c,d*2+2,h+1,f);
        a[d]=l(a[d*2+1],a[d*2+2]);
    }

    void u(int c,int d,int e,int f,int g){
        if(d==e){
            a[c]=g;
            return;
        }
        int h=(d+e)>>1;
        if(f<=h){
            u(c*2+1,d,h,f,g);
        }else{
            u(c*2+2,h+1,e,f,g);
        }
        a[c]=l(a[c*2+1],a[c*2+2]);
    }

    long q(int c,int d,int e,int f,int g){
        if(f<=d&&e<=g){
            return a[c];
        }
        if(e<f||d>g){
            return 1;
        }
        int h=(d+e)>>1;
        return l(q(c*2+1,d,h,f,g),q(c*2+2,h+1,e,f,g));
    }

    public ArrayList<Long> RangeLCMQuery(int[] c,int[][] d){
        b=c.length;
        a=new long[4*b];
        p(c,0,0,b-1);
        ArrayList<Long> e=new ArrayList<>();
        for(int i=0;i<d.length;i++){
            if(d[i][0]==1){
                u(0,0,b-1,d[i][1],d[i][2]);
            }else{
                e.add(q(0,0,b-1,d[i][1],d[i][2]));
            }
        }
        return e;
    }
}