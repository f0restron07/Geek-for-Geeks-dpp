class Solution {
    public ArrayList<String> generateIp(String s) {
        ArrayList<String> r=new ArrayList<>();
        int n=s.length();
        if(n<4||n>12) return r;
        bt(s,0,new ArrayList<>(),r);
        return r;
    }
    
    void bt(String s,int i,ArrayList<String> p,ArrayList<String> r){
        if(p.size()==4){
            if(i==s.length()) r.add(String.join(".",p));
            return;
        }
        for(int l=1;l<=3&&i+l<=s.length();l++){
            String t=s.substring(i,i+l);
            if(ok(t)){
                p.add(t);
                bt(s,i+l,p,r);
                p.remove(p.size()-1);
            }
        }
    }
    
    boolean ok(String t){
        if(t.length()>1&&t.charAt(0)=='0') return false;
        int v=Integer.parseInt(t);
        return v>=0&&v<=255;
    }
}