/* Structure of binary tree Node
class Node {
    public:
    int data;
    Node *left, *right;
    Node(int x) {
        data = x;
        left = right = nullptr;
    }
};
*/

class Solution {
  public:
    bool areAnagrams(Node* root1, Node* root2){
        queue<Node*> q1,q2;
        if(root1){
            q1.push(root1);
        }
        if(root2){
            q2.push(root2);
        }
        while(!q1.empty()&&!q2.empty()){
            int s1=q1.size();
            int s2=q2.size();
            if(s1!=s2){
                return false;
            }
            unordered_map<int,int> freq;
            for(int i=0;i<s1;i++){
                Node* a=q1.front();
                q1.pop();
                freq[a->data]++;
                if(a->left){
                    q1.push(a->left);
                }
                if(a->right){
                    q1.push(a->right);
                }
            }
            for(int i=0;i<s2;i++){
                Node* b=q2.front();
                q2.pop();
                freq[b->data]--;
                if(b->left){
                    q2.push(b->left);
                }
                if(b->right){
                    q2.push(b->right);
                }
            }
            for(auto& p:freq){
                if(p.second!=0){
                    return false;
                }
            }
        }
        return q1.empty()&&q2.empty();
    }
};