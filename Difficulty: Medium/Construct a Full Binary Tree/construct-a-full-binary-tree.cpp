class Solution {
  public:
    Node* f(vector<int>&p,vector<int>&q,unordered_map<int,int>&m,int s,int e,int u){
        if(s>e)return nullptr;
        Node*r=new Node(p[s]);
        if(s==e)return r;
        int k=m[q[u+1]];
        r->left=f(p,q,m,s+1,k-1,u+e-k+2);
        r->right=f(p,q,m,k,e,u+1);
        return r;
    }
    Node *constructBinaryTree(vector<int> &pre, vector<int> &preMirror) {
        int n=pre.size();
        unordered_map<int,int>m;
        for(int i=0;i<n;i++)m[pre[i]]=i;
        return f(pre,preMirror,m,0,n-1,0);
    }
};