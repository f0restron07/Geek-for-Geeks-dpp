class Solution{
    public boolean palindromePair(String[] arr){
        java.util.HashMap<String,Integer> a=new java.util.HashMap<>();
        for(int i=0;i<arr.length;i++){
            a.put(arr[i],i);
        }
        for(int i=0;i<arr.length;i++){
            String b=arr[i];
            int c=b.length();
            for(int j=0;j<=c;j++){
                String d=b.substring(0,j);
                String e=b.substring(j);
                if(pal(e)){
                    String f=rev(d);
                    Integer g=a.get(f);
                    if(g!=null&&g!=i){
                        return true;
                    }
                }
                if(j!=0&&pal(d)){
                    String f=rev(e);
                    Integer g=a.get(f);
                    if(g!=null&&g!=i){
                        return true;
                    }
                }
            }
        }
        return false;
    }
    boolean pal(String a){
        int b=0;
        int c=a.length()-1;
        while(b<c){
            if(a.charAt(b)!=a.charAt(c)){
                return false;
            }
            b++;
            c--;
        }
        return true;
    }
    String rev(String a){
        char[] b=a.toCharArray();
        int c=0;
        int d=b.length-1;
        while(c<d){
            char e=b[c];
            b[c]=b[d];
            b[d]=e;
            c++;
            d--;
        }
        return new String(b);
    }
}