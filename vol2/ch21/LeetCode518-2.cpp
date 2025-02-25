class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n=coins.size();
        vector<int> dp(amount+1,0);
        dp[0]=1;
        for (int i=1;i<=n;i++) {
            for (int j=1;j<=amount;j++) {
                if (j>=coins[i-1]) 					//可以选择装入和不装入
                    dp[j]+=dp[j-coins[i-1]];
            }
        }
        return dp[amount];
    }
};

