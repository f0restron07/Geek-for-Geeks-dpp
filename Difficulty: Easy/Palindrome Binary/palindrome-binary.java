class Solution {
    public boolean isBinaryPalindrome(int n) {
        String a=Integer.toBinaryString(n);
        return a.equals(new StringBuilder(a).reverse().toString());
    }
}