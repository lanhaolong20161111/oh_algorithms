class Solution {
    const long long INF=0x3f3f3f3f3f3f3f3f;
public:
    vector<long long> minimumCosts(vector<int>&regular,vector<int>&express,int expressCost) {
        int n=regular.size();
        vector<long long> dp1(n+1,INF);
        vector<long long> dp2(n+1,INF);
        vector<long long> cost(n);
        dp1[0]=0;
        dp2[0]=expressCost;
        for (int i=1;i<=n;i++) {
            dp1[i]=min(dp1[i-1],dp2[i-1])+regular[i-1];
            dp2[i]=min(dp2[i-1],dp1[i-1]+expressCost)+express[i-1];
            cost[i-1]=min(dp1[i],dp2[i]);
        }
        return cost;
    }
};

