class Solution{
    public int getSize(Node a){
        if(a==null){
            return 0;
        }
        return 1+getSize(a.left)+getSize(a.right);
    }
}