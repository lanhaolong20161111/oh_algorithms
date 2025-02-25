class Solution {
public:
  int minPathSum(vector<vector<int>>& grid) {
    int m=grid.size(),n=grid[0].size();
    vector<vector<int>> dp=vector(m,vector<int>(n,0));
    dp[0][0]=grid[0][0];            //起始位置：边界条件①
    for(int i=1;i<m;i++)            //第0列的情况：边界条件②
        dp[i][0]=dp[i-1][0]+grid[i][0];
    for(int j=1;j<n;j++)            //第0行的情况：边界条件③
        dp[0][j]=dp[0][j-1]+grid[0][j];
    for(int i=1;i<m;i++) {            //其他行列的情况
      for(int j=1;j<n;j++) {
          dp[i][j]=min(dp[i-1][j],dp[i][j-1])+grid[i][j];
      }
    }
    return dp[m-1][n-1];
  }
};

