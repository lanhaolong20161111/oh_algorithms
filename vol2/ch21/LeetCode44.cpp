class Solution {
public:
  bool isMatch(string s, string p) {
      int m=s.size(),n=p.size();
          auto dp=vector<vector<bool>>(m+1,vector<bool>(n+1,false));
          dp[0][0]=true;
          for (int j=1;j<=n;j++) {
            if (p[j-1]=='*') dp[0][j]=true;
              else break;
          }
          for (int i=1;i<=m;i++) {
              for (int j=1;j<=n;j++) {
                  if(p[j-1]!='*') {
                      if (p[j-1]=='?' || s[i-1]==p[j-1]) 
                          dp[i][j]=dp[i-1][j-1];
                  }
                  else {                            //p[j-1]=='*')
                      dp[i][j]=dp[i][j-1] || dp[i-1][j];
                  }
              }
          }
          return dp[m][n];
      }
};

