class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m=obstacleGrid.size(),n=obstacleGrid[0].size(); //������
        vector<vector<int>> dp=vector<vector<int>>(m,vector<int>(n,0));
        for (int i=0;i<m && obstacleGrid[i][0]==0;i++)
            dp[i][0]=1;                                     //��ʼ����0�п�ͷ�����ɿ�λ��
        for (int j=0;j<n && obstacleGrid[0][j]==0;j++)
            dp[0][j]=1;                                     //��ʼ����0�п�ͷ�����ɿ�λ��
        for (int i=1;i<m;i++) {
            for (int j=1;j<n;j++) {
                if(obstacleGrid[i][j]==0)       				//�����ϰ���
                    dp[i][j]=dp[i-1][j]+dp[i][j-1];
            }
        }
        return dp[m-1][n-1];
    }
};

