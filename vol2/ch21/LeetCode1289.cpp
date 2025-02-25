class Solution {
  const int INF=0x3f3f3f3f;
public:
  int minFallingPathSum(vector<vector<int>>& grid) {
    int n=grid.size();
    vector<vector<int>> dp=vector<vector<int>>(n,vector<int>(n,0));
    for (int j=0;j<n;j++)             //第0行:边界条件
      dp[0][j]=grid[0][j];
    for (int i=1;i<n;i++) {           //考虑第i行
      for (int j=0;j<n;j++) {         //考虑第i行的第j列
        int tmp=INF;
        for (int k=0;k<n;k++) {       //考虑第i-1行的第k列
          if (k!=j) tmp=min(tmp,dp[i-1][k]);
        }
        dp[i][j]=grid[i][j]+tmp;
      }
    }
    int ans=dp[n-1][0];             //求dp[n-1]中的最小值
    for (int j=1;j<n;j++) {
        ans=min(ans,dp[n-1][j]);
    }
    return ans;
  }
};

