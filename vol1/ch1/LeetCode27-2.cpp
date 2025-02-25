class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int k=0;
        for (int i=0;i<nums.size();i++) {
            if (nums[i]==val) k++;				//nums[i]为要删除的元素
            else	  nums[i-k]=nums[i];			//nums[i]为要保留的元素
        }
        return nums.size()-k;
    }
};

