class Solution {
  public:
    Node* lca(Node* node,int p,int q){
        if(!node){
            return nullptr;
        }
        if(node->data==p||node->data==q){
            return node;
        }
        Node* L=lca(node->left,p,q);
        Node* R=lca(node->right,p,q);
        if(L&&R){
            return node;
        }
        return L?L:R;
    }
    bool countDown(Node* node,int t,int cameDir,int& turns){
        if(!node){
            return false;
        }
        if(node->data==t){
            return true;
        }
        if(countDown(node->left,t,0,turns)){
            if(cameDir!=-1&&cameDir!=0){
                turns++;
            }
            return true;
        }
        if(countDown(node->right,t,1,turns)){
            if(cameDir!=-1&&cameDir!=1){
                turns++;
            }
            return true;
        }
        return false;
    }
    int downTurns(Node* a,int target){
        int turns=0;
        countDown(a,target,-1,turns);
        return turns;
    }
    int numberOfTurns(Node* root,int p,int q){
        Node* a=lca(root,p,q);
        if(a->data==p||a->data==q){
            int desc=(a->data==p)?q:p;
            int tn=downTurns(a,desc);
            return tn>0?tn:-1;
        }
        int tp=downTurns(a,p);
        int tq=downTurns(a,q);
        int total=tp+tq+1;
        return total>0?total:-1;
    }
};