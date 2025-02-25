class Solution {
public:
   	int jump(vector<int>& nums) {
        	int n=nums.size();
        	if(n==1) return 0;
        	int dp[n];
        	memset(dp,0x3f,sizeof(dp));			//����Ԫ�س�ʼ��Ϊ��
        	dp[0]=0;
        	for(int j=1;j<n;j++) {
            	for(int i=0;i<j;i++) {
                	if(nums[i]+i>=j)			//��λ��i����λ��j
                    	dp[j]=min(dp[j],dp[i]+1); 
            	}
        	}
        	return dp[n-1];
	}
};

