class Solution {
    public int maximumLength(int[] b, int k) {
        int n = b.length;
        int[][] dp = new int[n + 5][k + 5];
        
        for(int i = 0; i <= n-1; i++) {
            Arrays.fill(dp[i], 1);
            
            for(int j = 0; j <= k; j++) {
                for(int i1 = i-1; i1 >= 0; i1--) {
                    if(b[i1] != b[i]) {
                        if(j != 0) {
                            dp[i][j] = Math.max(dp[i][j], 1 + dp[i1][j-1]);
                        }
                    } else {
                        dp[i][j] = Math.max(dp[i][j], 1 + dp[i1][j]);
                    }
                }
            }
        }
        
        int max = 0; 
        for(int i = 0; i <= n-1; i++) {
            int u = dp[i][k];
            max = Math.max(max, u);
        }
        
        return max;
    }
}