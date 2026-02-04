class Solution {
    public int getLastMoment(int n, int left[], int right[]) {
        int mxt=0;

        for (int p:left)
            if (p>mxt) mxt=p;

        for (int p:right)
            if (n-p>mxt) mxt=n-p;

        return mxt;
    }
}
