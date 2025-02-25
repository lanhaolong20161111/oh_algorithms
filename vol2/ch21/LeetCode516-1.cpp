class Solution {
public:
  int longestPalindromeSubseq(string &s) {
    int n=s.size();
      if(n==1) return 1;
      auto dp=vector<vector<int>>(n,vector<int>(n,0));
      for(int i=0;i<n;i++) dp[i][i]=1;        //���䳤��Ϊ1�����
      for(int i=0;i<n-1;i++) {            //���䳤��Ϊ2�����
        if(s[i]==s[i+1]) dp[i][i+1]=2;
        else dp[i][i+1]=1; 
    }
    for(int length=3;length<=n;length++) {       //���䳤��Ϊ3,4���������
      for(int i=0;i<=n-length;i++) {
        int j=i+length-1;
          if(s[i]==s[j])
            dp[i][j]=dp[i+1][j-1]+2;
          else
            dp[i][j]=max(dp[i][j-1],dp[i+1][j]);
        }
     }
    return dp[0][n-1];
   }
};

