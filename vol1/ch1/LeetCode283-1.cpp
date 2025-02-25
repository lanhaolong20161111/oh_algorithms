class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int k=0;
        for(int i=0;i<nums.size();i++) {
            if (nums[i]!=0) {           //将保留的元素重新插入
                nums[k]=nums[i];
                k++;
            }
        }
        for(int i=k;i<nums.size();i++)
            nums[i]=0;
    }
};

