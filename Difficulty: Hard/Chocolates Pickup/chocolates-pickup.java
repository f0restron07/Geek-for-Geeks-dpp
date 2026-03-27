class Solution {
    public int maxChocolate(int grid[][]) {
        int n = grid.length, m = grid[0].length;
        int[][] front = new int[m][m];
        int[][] cur = new int[m][m];

        for (int j1 = 0; j1 < m; j1++) {
            for (int j2 = 0; j2 < m; j2++) {
                if (j1 == j2) front[j1][j2] = grid[n - 1][j1];
                else front[j1][j2] = grid[n - 1][j1] + grid[n - 1][j2];
            }
        }

        for (int i = n - 2; i >= 0; i--) {
            for (int j1 = 0; j1 < m; j1++) {
                for (int j2 = 0; j2 < m; j2++) {
                    int maxi = 0;

                    for (int d1 = -1; d1 <= 1; d1++) {
                        for (int d2 = -1; d2 <= 1; d2++) {
                            int nj1 = j1 + d1;
                            int nj2 = j2 + d2;

                            if (nj1 >= 0 && nj1 < m && nj2 >= 0 && nj2 < m) {
                                int val;
                                if (j1 == j2) val = grid[i][j1];
                                else val = grid[i][j1] + grid[i][j2];

                                val += front[nj1][nj2];
                                maxi = Math.max(maxi, val);
                            }
                        }
                    }
                    cur[j1][j2] = maxi;
                }
            }

            for (int j1 = 0; j1 < m; j1++) {
                for (int j2 = 0; j2 < m; j2++) {
                    front[j1][j2] = cur[j1][j2];
                }
            }
        }

        return front[0][m - 1];
    }
}