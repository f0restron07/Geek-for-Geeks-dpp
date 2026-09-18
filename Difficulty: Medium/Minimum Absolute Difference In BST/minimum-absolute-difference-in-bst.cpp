/* Binary Tree Node Structure
class Node {
public:
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
}; 
*/

class Solution {
  public:
    int prev;
    int best;
    void inorder(Node* n){
        if(!n){
            return;
        }
        inorder(n->left);
        if(prev!=-1){
            best=min(best,n->data-prev);
        }
        prev=n->data;
        inorder(n->right);
    }
    int absDiff(Node *root){
        prev=-1;
        best=INT_MAX;
        inorder(root);
        return best;
    }
};