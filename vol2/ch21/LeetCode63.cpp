class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m=obstacleGrid.size(),n=obstacleGrid[0].size(); //行列数
        vector<vector<int>> dp=vector<vector<int>>(m,vector<int>(n,0));
        for (int i=0;i<m && obstacleGrid[i][0]==0;i++)
            dp[i][0]=1;                                     //初始化第0列开头的若干空位置
        for (int j=0;j<n && obstacleGrid[0][j]==0;j++)
            dp[0][j]=1;                                     //初始化第0行开头的若干空位置
        for (int i=1;i<m;i++) {
            for (int j=1;j<n;j++) {
                if(obstacleGrid[i][j]==0)       				//跳过障碍物
                    dp[i][j]=dp[i-1][j]+dp[i][j-1];
            }
        }
        return dp[m-1][n-1];
    }
};

