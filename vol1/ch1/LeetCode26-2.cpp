class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int k=0;
        for (int i=1;i<nums.size();i++) {			//首先保留nums[0]
            if (nums[i]==nums[i-1]) k++;      //nums[i]为要删除的元素
            else nums[i-k]=nums[i];         //nums[i]为要保留的元素
        }
        return nums.size()-k;
    }
};

