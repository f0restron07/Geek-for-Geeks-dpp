/*
Definition for Node
class Node {
    int data;
    Node left;
    Node right;

    Node(int x) {
        data = x;
        left = right = null;
    }
}
*/
class Solution {
    boolean a(Node b,Node c){
        if(b==null&&c==null){
            return true;
        }
        if(b==null||c==null){
            return false;
        }
        if(b.data!=c.data){
            return false;
        }
        return a(b.left,c.left)&&a(b.right,c.right);
    }
    public boolean isSubTree(Node t, Node s){
        if(s==null){
            return true;
        }
        if(t==null){
            return false;
        }
        if(a(t,s)){
            return true;
        }
        return isSubTree(t.left,s)||isSubTree(t.right,s);
    }
}