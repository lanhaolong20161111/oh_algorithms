class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int j=0;            //首先保留nums[0]
        for(int i=1;i<nums.size();i++) {
            if (nums[i]!=nums[j]) {              //nums[i]为保留的元素
                j++;                         //扩大保留元素区间
                if (j!=i)                   //序号i和j的两个元素交换
                    swap(nums[i],nums[j]); 
            }
        }
        return j+1;
    }
};

