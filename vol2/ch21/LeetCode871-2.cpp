typedef long long LL;
class Solution {
public:
    int minRefuelStops(int target,int startFuel,vector<vector<int>>& stations) {
        int n=stations.size();
        vector<LL> dp=vector<LL>(n+1,0);
        dp[0]=startFuel;
        for(int i=1;i<=n;i++) {
            for (int j=i;j>=1;j--) {
                if (dp[j-1]>=stations[i-1][0]) {
                    dp[j]=max(dp[j],dp[j-1]+stations[i-1][1]);
                }
            }
        }
        for (int j=0;j<=n;j++) {
            if (dp[j]>=target) return j;
        }
        return -1;
    }
};

