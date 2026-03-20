/*
class Node {
    int data;
    Node left, right;
    Node(int x) {
        data = x;
        left = right = null;
    }
}
*/

class Solution {
    public ArrayList<Node> findPreSuc(Node root, int key) {
        ArrayList<Node> r=new ArrayList<>();
        Node p=null,s=null,c=root;
        while(c!=null){
            if(c.data<key){
                p=c;
                c=c.right;
            }else{
                c=c.left;
            }
        }
        c=root;
        while(c!=null){
            if(c.data>key){
                s=c;
                c=c.left;
            }else{
                c=c.right;
            }
        }
        r.add(p);
        r.add(s);
        return r;
    }
}