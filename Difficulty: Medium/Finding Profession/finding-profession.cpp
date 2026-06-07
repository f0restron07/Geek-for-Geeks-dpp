class Solution {
  public:
    string profession(int level, int pos) {
        int a=pos-1;
        int b=__builtin_popcount(a);
        if(b%2==0){
            return "Engineer";
        }
        return "Doctor";
    }
};