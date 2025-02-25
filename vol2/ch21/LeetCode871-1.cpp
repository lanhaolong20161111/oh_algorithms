typedef long long LL;
class Solution {
public:
    int minRefuelStops(int target,int startFuel,vector<vector<int>>& stations) {
        int n=stations.size();
        vector<vector<LL>> dp=vector<vector<LL>>(n+1,vector<LL>(n+1,0));
        for(int i=0;i<=n;i++)
            dp[i][0]=startFuel;
        for(int i=1;i<=n;i++) {
            for (int j=1;j<=i;j++) {
                if(dp[i-1][j-1]<stations[i-1][0])
                    dp[i][j]=dp[i-1][j];        //²»¼ÓÓÍ
                else 
                    dp[i][j]=max(dp[i-1][j],dp[i-1][j-1]+stations[i-1][1]);
            }
        }
        for (int j=0;j<=n;j++) {
            if (dp[n][j]>=target) return j;
        }
        return -1;
    }
};

