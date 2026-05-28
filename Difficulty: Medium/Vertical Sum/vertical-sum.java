/* Structure of binary tree node
class Node{
public:
    int data;
    Node left, right;
    Node(int item)
    {
        data = item;
        left = right = null;
    }
}
*/
class Solution{
 public ArrayList<Integer> verticalSum(Node root){
  TreeMap<Integer,Integer> a=new TreeMap<>();
  b(root,0,a);
  return new ArrayList<>(a.values());
 }
 void b(Node n,int d,TreeMap<Integer,Integer> a){
  if(n==null)return;
  a.merge(d,n.data,Integer::sum);
  b(n.left,d-1,a);
  b(n.right,d+1,a);
 }
}