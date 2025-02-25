class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n=nums.size();
        if(n==1) return true;
        if(nums[0]==0) return false;
        int dp=nums[0];
        for(int i=1;i<n-1;i++) {
            dp=max(dp,i+nums[i]);
            if(dp>=n-1) return true; 
            if(dp==i) return false;
        }
        return true;
    }
};

