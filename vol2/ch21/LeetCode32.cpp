class Solution {
public:
  int longestValidParentheses(string s) {
    int n=s.size();
    vector<int> dp(n,0);              //一维动态规划数组
    int ans=0;
    for(int i=1;i<n;i++) {
      if (s[i]==')') {
        if (s[i-1]=='(') {
           if(i>=2) dp[i]=dp[i-2]+2;
           else dp[i]=2;
          }
          else if(i-dp[i-1]>0 && s[i-dp[i-1]-1]=='(') {
            if(i-dp[i-1]>=2) dp[i]=dp[i-1]+dp[i-dp[i-1]-2]+2;
            else dp[i]=dp[i-1]+2;
          }
      }
      ans=max(ans,dp[i]);
    }
    return ans;
  }
};

