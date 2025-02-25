class Solution {
  const int INF=0x3f3f3f3f; 
public:
    int tallestBillboard(vector<int>& rods) {
        int n=rods.size();
        int s=0;
        for(int e:rods) s+=e;
        vector<int> dp(s+1,-INF),ndp(s+1);
        dp[0]=0;
        for(int i=1;i<=n;i++) {
            ndp=dp;
            for(int j=0;j<=s;j++) {
                if(j+rods[i-1]<=s)  
                    ndp[j+rods[i-1]]=max(dp[j]+rods[i-1],ndp[j+rods[i-1]]);
                if( rods[i-1]<=j)
                    ndp[j-rods[i-1]]=max(dp[j],ndp[j-rods[i-1]]);
                else 
                    ndp[rods[i-1]-j]=max(ndp[rods[i-1]-j],dp[j]+rods[i-1]-j);
            }
            dp=ndp;
        }
        return dp[0];
    }
};

