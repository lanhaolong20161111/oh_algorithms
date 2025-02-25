class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int n=nums.size();
        int presum[n];											//前缀和数组
        presum[0]=nums[0];
        int maxpre=presum[0],minpre=presum[0];
        for(int i=1;i<n;i++) {
            presum[i]=presum[i-1]+nums[i];
            maxpre=max(maxpre,presum[i]);
            minpre=min(minpre,presum[i]);
        }
        if(minpre>=0) return maxpre;					//maxpre和minpre均为正数
        if(maxpre<=0) return abs(minpre);			//maxpre和minpre均为负数
        return maxpre-minpre;
    }
};

