class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums){
        int ans=0,cur=0;
        for (int i=0;i<nums.size();i++) {
            if (nums[i]==0) cur=0;
            else cur++;
            if (cur>ans) ans=cur;
        }
        return ans;
    }
};

