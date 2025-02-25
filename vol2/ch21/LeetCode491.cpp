class Solution {
    set<vector<int>> hset;
    vector<int> dp;
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n=nums.size();
        int maxlen=0,ans=0;
        vector<int> dp=vector<int>(n,0);
        vector<int> cnt=vector<int>(n,0);
        for(int i=0;i<n;i++) {
            dp[i]=1;
            cnt[i]=1;
            for(int j=0;j<i;j++) {
                if(nums[i]>nums[j]) {
                    if(dp[j]+1>dp[i]) {     //找到更大的dp[i]
                        dp[i]=dp[j]+1;				//重置dp[i]
                        cnt[i]=cnt[j];      		//重置计数
                    }
                    else if(dp[j]+1==dp[i])  //找到相同的dp[i]
                        cnt[i]+=cnt[j];				//递增计数
                }
            }
            if(dp[i]>maxlen) {      		//找到更大的maxlen
                maxlen=dp[i];
                ans=cnt[i];
            }
            else if(dp[i]==maxlen)			//找到相同的maxlen
                ans+=cnt[i];
        }
        return ans;
    }
};

