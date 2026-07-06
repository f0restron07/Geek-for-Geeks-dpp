class Solution{
  public:
    int maxPathSum(vector<int>&a,vector<int>&b){
        int i=0,j=0,p=0,q=0,r=0,n=a.size(),m=b.size();
        while(i<n&&j<m){
            if(a[i]<b[j]){p+=a[i++];}
            else if(a[i]>b[j]){q+=b[j++];}
            else{r+=max(p,q)+a[i++];j++;p=0;q=0;}
        }
        while(i<n){p+=a[i++];}
        while(j<m){q+=b[j++];}
        return r+max(p,q);
    }
};