class Solution {
    String URLify(String s) {
        StringBuilder a=new StringBuilder();
        for(int i=0;i<s.length();i++){
            char c=s.charAt(i);
            if(c==' '){
                a.append("%20");
            }else{
                a.append(c);
            }
        }
        return a.toString();
    }
}