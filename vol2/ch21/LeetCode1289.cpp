class Solution {
  const int INF=0x3f3f3f3f;
public:
  int minFallingPathSum(vector<vector<int>>& grid) {
    int n=grid.size();
    vector<vector<int>> dp=vector<vector<int>>(n,vector<int>(n,0));
    for (int j=0;j<n;j++)             //��0��:�߽�����
      dp[0][j]=grid[0][j];
    for (int i=1;i<n;i++) {           //���ǵ�i��
      for (int j=0;j<n;j++) {         //���ǵ�i�еĵ�j��
        int tmp=INF;
        for (int k=0;k<n;k++) {       //���ǵ�i-1�еĵ�k��
          if (k!=j) tmp=min(tmp,dp[i-1][k]);
        }
        dp[i][j]=grid[i][j]+tmp;
      }
    }
    int ans=dp[n-1][0];             //��dp[n-1]�е���Сֵ
    for (int j=1;j<n;j++) {
        ans=min(ans,dp[n-1][j]);
    }
    return ans;
  }
};

