/* Structure of Binary Tree Node
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};
*/
class Solution {
  public:
    int best;
    int dfs(Node* n){
        if(!n){
            return 0;
        }
        int a=dfs(n->left);
        int b=dfs(n->right);
        int c=1;
        if(n->left&&n->left->data==n->data+1){
            c=max(c,1+a);
        }
        if(n->right&&n->right->data==n->data+1){
            c=max(c,1+b);
        }
        best=max(best,c);
        return c;
    }
    int longestConsecutive(Node* root){
        best=0;
        dfs(root);
        if(best<2){
            return -1;
        }
        return best;
    }
};