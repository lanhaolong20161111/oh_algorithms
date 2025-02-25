class Solution {
    const int INF=0x3f3f3f3f;
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int m=dungeon.size(),n=dungeon[0].size();
        vector<vector<int>> dp(m+1,vector<int>(n+1,INF));
        dp[m][n-1]=dp[m-1][n]=1;
        for (int i=m-1;i>=0; i--) {
            for (int j=n-1;j>=0;j--) {
                int mind=min(dp[i+1][j],dp[i][j+1]);
                dp[i][j]=max(mind-dungeon[i][j],1);
            }
        }
        return dp[0][0];
    }
};

