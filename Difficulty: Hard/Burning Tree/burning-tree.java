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
    public int minTime(Node root, int target) {
        Map<Node,Node> par = new HashMap<>();
        Node tgt = mapParent(root, target, par);
        
        Set<Node> vis = new HashSet<>();
        Queue<Node> q = new LinkedList<>();
        q.offer(tgt);
        vis.add(tgt);
        int t = 0;
        
        while(!q.isEmpty()) {
            int sz = q.size();
            boolean burned = false;
            for(int i = 0; i < sz; i++) {
                Node cur = q.poll();
                if(cur.left != null && !vis.contains(cur.left)) {
                    vis.add(cur.left); q.offer(cur.left); burned = true;
                }
                if(cur.right != null && !vis.contains(cur.right)) {
                    vis.add(cur.right); q.offer(cur.right); burned = true;
                }
                if(par.get(cur) != null && !vis.contains(par.get(cur))) {
                    vis.add(par.get(cur)); q.offer(par.get(cur)); burned = true;
                }
            }
            if(burned) t++;
        }
        return t;
    }
    
    Node mapParent(Node root, int target, Map<Node,Node> par) {
        Node tgt = null;
        Queue<Node> q = new LinkedList<>();
        q.offer(root);
        while(!q.isEmpty()) {
            Node cur = q.poll();
            if(cur.data == target) tgt = cur;
            if(cur.left != null) { par.put(cur.left, cur); q.offer(cur.left); }
            if(cur.right != null) { par.put(cur.right, cur); q.offer(cur.right); }
        }
        return tgt;
    }
}