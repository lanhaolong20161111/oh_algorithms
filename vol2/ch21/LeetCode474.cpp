class Solution {
public:
    pair<int,int> Count(string&str) {
        int len=str.length();
        int cnt0=0,cnt1=0;
        for (int i=0;i<len;i++) {
            if(str[i]=='1') cnt1++;
            else cnt0++;
        }
        return pair<int,int>(cnt0,cnt1);
    }
    int findMaxForm(vector<string>& strs,int m,int n) {
        int len=strs.size();
        vector<vector<int>> dp(m+1,vector<int>(n+1,0));
        for (int i=1;i<=len;i++) {
            auto [cnt0,cnt1]=Count(strs[i-1]);
            for (int j=m;j>=cnt0;j--) {
                for (int k=n;k>=cnt1;k--)
                    dp[j][k]=max(dp[j][k],dp[j-cnt0][k-cnt1]+1);
            }
        }
        return dp[m][n];
    }
};

