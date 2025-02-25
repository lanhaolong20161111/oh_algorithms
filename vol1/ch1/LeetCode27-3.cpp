class Solution {
public:
    int removeElement(vector<int>& nums,int val) {
        int j=-1;
        for(int i=0;i<nums.size();i++) {
            if (nums[i]!=val) {              //nums[i]为保留的元素
                j++;                         //扩大保留元素区间
                if (j!=i)                   //序号i和j的两个元素交换
                    swap(nums[i],nums[j]); 
            }
        }
        return j+1;                      //新数组长度为j+1
    }
};

