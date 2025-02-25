class Solution {
public:
    int longestCommonSubsequence(string text1,string text2) {
        int m=text1.length(),n=text2.length();
        auto dp=vector<vector<int>>(m+1,vector<int>(n+1,0));
        dp[0][0]=0;									//可省略
      for(int i=0;i<=m;i++)						//可省略
        dp[i][0]=0;
      for(int j=0;j<=n;j++)						//可省略
        dp[0][j]=0;
      for(int i=1;i<=m;i++) {
        for(int j=1;j<=n;j++) {
          if(text1[i-1]==text2[j-1])
            dp[i][j]=dp[i-1][j-1]+1;
          else
            dp[i][j]=max(dp[i][j-1],dp[i-1][j]);
        }
        }
      return dp[m][n];
    }
};

