/*
class Node {
    int data;
    Node left, right;

    Node(int val) {
        this.data = val;
        this.left = null;
        this.right = null;
    }
}
*/
class Solution {
    public ArrayList<Integer> topView(Node root) {
        ArrayList<Integer> ans=new ArrayList<>();
        if(root==null) return ans;
        
        TreeMap<Integer,Integer> map=new TreeMap<>();
        Queue<int[]> q=new LinkedList<>();
        Queue<Node> nodes=new LinkedList<>();
        
        nodes.offer(root);
        q.offer(new int[]{0});
        
        while(!nodes.isEmpty()){
            Node curr=nodes.poll();
            int hd=q.poll()[0];
            
            if(!map.containsKey(hd)){
                map.put(hd,curr.data);
            }
            
            if(curr.left!=null){
                nodes.offer(curr.left);
                q.offer(new int[]{hd-1});
            }
            if(curr.right!=null){
                nodes.offer(curr.right);
                q.offer(new int[]{hd+1});
            }
        }
        
        for(int val:map.values()) ans.add(val);
        return ans;
    }
}