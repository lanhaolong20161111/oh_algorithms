class Solution {
public:
    bool canJump(vector<int>& nums) {
        return dfs(nums,nums.size()-1);
    }
    bool dfs(vector<int> &nums,int i) {    //回溯算法
        if(i==0) return true;
        else {
            for(int j=i-1;j>=0; j--) {		//试探位置i-1～0
                if(j+nums[j]>=i)       //出位置j可以跳到位置i
                    return dfs(nums,j);
            }
        }
        return false;
    }
};

