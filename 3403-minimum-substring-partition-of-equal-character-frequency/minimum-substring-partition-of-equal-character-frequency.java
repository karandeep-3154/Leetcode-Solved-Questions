class Solution {
    
    public boolean check(int[] b) {
        int c1 = 0;
        for (int i = 0; i < 26; i++) {
            if (b[i] >= 1) {
                if (c1 == 0) {
                    c1 = b[i];
                }
                if (b[i] != c1) {
                    return false;
                }
            }
        }
        return true;
    }

    public int minimumSubstringsInPartition(String s) {
        int n = s.length();
        int[] dp = new int[n + 5];
        String g = "." + s;
        dp[1] = 1;
        for (int i = 2; i <= n; i++) {
            int v = 100000;
            int[] b = new int[26];
            for (int j = i; j >= 1; j--) {
                char u = g.charAt(j);
                int y = (int) u - 97;
                b[y]++;
                if (check(b)) {
                    v = Math.min(v, 1 + dp[j - 1]);
                }
            }
            dp[i] = v;
        }
        return dp[n];
    }
}