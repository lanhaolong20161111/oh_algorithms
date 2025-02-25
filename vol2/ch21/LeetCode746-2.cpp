class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n=cost.size();
        vector<int> dp=vector<int>(3);
        dp[0]=dp[1]=0;
        for (int i=2;i<=n;i++)
            dp[i%3]=min(dp[(i-1)%3]+cost[i-1],dp[(i-2)%3]+cost[i-2]);
        return dp[n%3];
    }
};

