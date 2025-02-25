class Solution {
  const int INF=0x3f3f3f3f;
public:
  int getMoneyAmount(int n) {
    if(n<=3) return n-1;
    vector<vector<int>>dp(n+1,vector<int>(n+1,0));
    for(int i=1;i<=n;i++)
        dp[i][i]=0;
    for(int length=2;length<=n;length++) {
      for(int i=1;i<=n-length+1;i++) {
        int j=i+length-1;
        int minCost=INF;            //Ϊ����min����ʼ��Ϊ��
        for (int m=i;m<j;m++)       //ö��[i,j]�����еĲ²��m
          minCost=min(minCost,m+max(dp[i][m-1],dp[m+1][j]));
        dp[i][j]=minCost;
      }
    }
    return dp[1][n];
  }
};

