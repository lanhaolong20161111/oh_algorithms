class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n=nums.size();
        int j=-1;
        for(int i=0;i<n;i++) {
            if (nums[i]!=0) {              //nums[i]为保留的元素
                j++;                         //扩大保留元素区间
                if (j!=i)                   //序号i和j的两个元素交换
                    swap(nums[i],nums[j]); 
            }
        }
        for(int i=j+1;i<n;i++)
            nums[i]=0;
    }
};

