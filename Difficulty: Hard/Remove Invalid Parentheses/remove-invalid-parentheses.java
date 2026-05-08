class Solution{
    public List<String> validParenthesis(String s){
        int a=0;
        int b=0;
        int c=s.length();
        for(int i=0;i<c;i++){
            char d=s.charAt(i);
            if(d=='('){
                a++;
            }else if(d==')'){
                if(a>0){
                    a--;
                }else{
                    b++;
                }
            }
        }
        TreeSet<String> e=new TreeSet<>();
        g(s,0,0,0,a,b,new StringBuilder(),e);
        return new ArrayList<>(e);
    }
    void g(String s,int a,int b,int c,int d,int e,StringBuilder f,TreeSet<String> h){
        if(a==s.length()){
            if(d==0&&e==0&&b==c){
                h.add(f.toString());
            }
            return;
        }
        char p=s.charAt(a);
        int q=f.length();
        if(p=='('){
            if(d>0){
                g(s,a+1,b,c,d-1,e,f,h);
            }
            f.append(p);
            g(s,a+1,b+1,c,d,e,f,h);
            f.setLength(q);
        }else if(p==')'){
            if(e>0){
                g(s,a+1,b,c,d,e-1,f,h);
            }
            if(c<b){
                f.append(p);
                g(s,a+1,b,c+1,d,e,f,h);
                f.setLength(q);
            }
        }else{
            f.append(p);
            g(s,a+1,b,c,d,e,f,h);
            f.setLength(q);
        }
    }
}