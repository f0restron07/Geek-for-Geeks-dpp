class Solution{
 public boolean wifiRange(String s,int x){
  int n=s.length(),a=-n-1;
  int[]b=new int[n];
  for(int i=0;i<n;i++){
   if(s.charAt(i)=='1')a=i;
   b[i]=i-a;
  }
  a=2*n;
  for(int i=n-1;i>=0;i--){
   if(s.charAt(i)=='1')a=i;
   if(Math.min(b[i],a-i)>x)return false;
  }
  return true;
 }
}