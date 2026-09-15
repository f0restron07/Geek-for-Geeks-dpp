/* Binary Tree Node Structure
class Node {
  public:
    int data;
    Node *left;
    Node *right;

    Node(int x) {
        data = x;
        left = nullptr;
        right = nullptr;
    }
};
*/

class Solution {
  public:
    void dfs(Node* n,int level,vector<int>& leaves){
        if(!n){
            return;
        }
        if(!n->left&&!n->right){
            leaves.push_back(level);
            return;
        }
        dfs(n->left,level+1,leaves);
        dfs(n->right,level+1,leaves);
    }
    int getCount(Node *root, int k){
        vector<int> leaves;
        dfs(root,1,leaves);
        sort(leaves.begin(),leaves.end());
        int cnt=0;
        int total=0;
        for(int c:leaves){
            if(total+c<=k){
                total+=c;
                cnt++;
            }else{
                break;
            }
        }
        return cnt;
    }
};