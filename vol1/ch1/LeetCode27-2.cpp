class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int k=0;
        for (int i=0;i<nums.size();i++) {
            if (nums[i]==val) k++;				//nums[i]ΪҪɾ����Ԫ��
            else	  nums[i-k]=nums[i];			//nums[i]ΪҪ������Ԫ��
        }
        return nums.size()-k;
    }
};

