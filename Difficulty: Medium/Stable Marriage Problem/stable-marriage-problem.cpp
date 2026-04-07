class Solution {
  public:
    vector<int> stableMarriage(vector<vector<int>> &men, vector<vector<int>> &women) {
        int n = men.size();
        
        vector<vector<int>> rank(n, vector<int>(n));
        for (int w = 0; w < n; w++) {
            for (int i = 0; i < n; i++) {
                rank[w][women[w][i]] = i;
            }
        }
        
        vector<int> wife(n, -1);
        vector<int> husband(n, -1);
        vector<int> nextProposal(n, 0);
        
        queue<int> freeMen;
        for (int m = 0; m < n; m++) {
            freeMen.push(m);
        }
        
        while (!freeMen.empty()) {
            int m = freeMen.front();
            freeMen.pop();
            
            int w = men[m][nextProposal[m]];
            nextProposal[m]++;
            
            if (husband[w] == -1) {
                husband[w] = m;
                wife[m] = w;
            }
            else {
                int currentMan = husband[w];
                
                if (rank[w][m] < rank[w][currentMan]) {
                    husband[w] = m;
                    wife[m] = w;
                    wife[currentMan] = -1;
                    freeMen.push(currentMan);
                }
                else {
                    freeMen.push(m);
                }
            }
        }
        
        return wife;
    }
};