/* Structure for Tree Node
class Node {
    int data;
    Node left, right;

    // Constructor
    Node(int val) {
        data = val;
        left = null;
        right = null;
    }
};
*/
class Solution{
    public void toSumTree(Node root){
        a(root);
    }
    int a(Node b){
        if(b==null){
            return 0;
        }
        int c=b.data;
        int d=a(b.left);
        int e=a(b.right);
        b.data=d+e;
        return c+d+e;
    }
}