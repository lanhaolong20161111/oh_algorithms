class Solution {
public:
    int longestRepeatingSubstring(string s) {
        int n=s.size();
        auto dp=vector<vector<int>>(n,vector<int>(n,0));
        int ans=0;
        for(int i=0;i<n;i++) {
            for(int j=i+1;j<n;j++) {
                if(s[i]==s[j]) {
                    if(i==0) dp[i][j]=1;
                    else dp[i][j]=dp[i-1][j-1]+1;
                }
                ans=max(ans,dp[i][j]);
            }
        }
        return ans;
    }
};

