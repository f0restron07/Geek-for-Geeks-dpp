// class Node
// {
//     int data;
//     Node left, right;

//     public Node(int d)
//     {
//         data = d;
//         left = right = null;
//     }
// }

class Solution {
    static int r;
    static int largestBst(Node root) {
        r=0;
        go(root);
        return r;
    }
    static int[] go(Node n) {
        if(n==null) {
            return new int[]{1,Integer.MAX_VALUE,Integer.MIN_VALUE,0};
        }
        int[] l=go(n.left);
        int[] ri=go(n.right);

        if(l[0]==1&&ri[0]==1&&l[2]<n.data&&ri[1]>n.data) {
            int s=l[3]+ri[3]+1;
            r=Math.max(r,s);
            return new int[]{1,Math.min(l[1],n.data),Math.max(ri[2],n.data),s};
        }
        return new int[]{0,0,0,0};
    }
}