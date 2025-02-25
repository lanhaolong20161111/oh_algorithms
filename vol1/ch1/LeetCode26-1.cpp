class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int k=1;										//首先保留nums[0]
        for(int i=1;i<nums.size();i++) {
            if (nums[i]!=nums[i-1]) {           //将保留的元素重新插入
                nums[k]=nums[i];
                k++;
            }
        }
        return k;
    }
};

