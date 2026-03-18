/*
class Node {
    int data;
    Node left;
    Node right;
    Node(int data) {
        this.data = data;
        left = null;
        right = null;
    }
}
*/

class Solution {
    int m;
    public int distCandy(Node root) {
        // code here
        m=0;
        f(root);
        return m;
    }
     int f(Node n){
        if(n==null)return 0;
        int l=f(n.left),r=f(n.right);
        m+=Math.abs(l)+Math.abs(r);
        return n.data+l+r-1;
    }
}