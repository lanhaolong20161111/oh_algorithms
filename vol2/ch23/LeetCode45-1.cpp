class Solution {
public:
   	int jump(vector<int>& nums) {
        	int n=nums.size();
        	if(n==1) return 0;
        	int dp[n];
        	memset(dp,0x3f,sizeof(dp));			//所有元素初始化为∞
        	dp[0]=0;
        	for(int j=1;j<n;j++) {
            	for(int i=0;i<j;i++) {
                	if(nums[i]+i>=j)			//从位置i跳到位置j
                    	dp[j]=min(dp[j],dp[i]+1); 
            	}
        	}
        	return dp[n-1];
	}
};

