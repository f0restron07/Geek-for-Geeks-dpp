/* Structure of Binary Tree Node
class Node {
  public:
    int data;
    Node *left;
    Node *right;
    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};*/

class Solution {
  public:
    int best;
    void dfs(Node* n,int mx){
        if(!n){
            return;
        }
        if(mx!=INT_MIN){
            best=max(best,mx-n->data);
        }
        int nm=(mx==INT_MIN)?n->data:max(mx,n->data);
        dfs(n->left,nm);
        dfs(n->right,nm);
    }
    int maxDiff(Node* root){
        best=INT_MIN;
        dfs(root,INT_MIN);
        return best;
    }
};