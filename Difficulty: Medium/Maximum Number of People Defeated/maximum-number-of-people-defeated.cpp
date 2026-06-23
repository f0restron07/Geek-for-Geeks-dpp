class Solution {
  public:
    int maxPeopleDefeated(int p) {
        int i=1;
        long long a=0;
        while(a+(long long)i*i<=p){
            a+=(long long)i*i;
            i++;
        }
        return i-1;
    }
};