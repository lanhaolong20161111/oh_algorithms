class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n=nums.size();
        if (n<=2) return n;
        int j=1;            //首先保留nums[0]和nums[1]
        for(int i=2;i<n;i++) {
            if (!(nums[j-1]==nums[j] && nums[i]==nums[j])) {      //nums[i]为保留的元素
                j++;                         //扩大保留元素区间
                if (j!=i)                   //序号i和j的两个元素交换
                    swap(nums[i],nums[j]); 
            }
        }
        return j+1;
    }
};

