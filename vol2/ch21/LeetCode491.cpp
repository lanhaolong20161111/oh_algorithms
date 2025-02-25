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
                    if(dp[j]+1>dp[i]) {     //�ҵ������dp[i]
                        dp[i]=dp[j]+1;				//����dp[i]
                        cnt[i]=cnt[j];      		//���ü���
                    }
                    else if(dp[j]+1==dp[i])  //�ҵ���ͬ��dp[i]
                        cnt[i]+=cnt[j];				//��������
                }
            }
            if(dp[i]>maxlen) {      		//�ҵ������maxlen
                maxlen=dp[i];
                ans=cnt[i];
            }
            else if(dp[i]==maxlen)			//�ҵ���ͬ��maxlen
                ans+=cnt[i];
        }
        return ans;
    }
};

