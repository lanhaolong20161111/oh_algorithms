class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int k=0;
        for (int i=1;i<nums.size();i++) {			//���ȱ���nums[0]
            if (nums[i]==nums[i-1]) k++;      //nums[i]ΪҪɾ����Ԫ��
            else nums[i-k]=nums[i];         //nums[i]ΪҪ������Ԫ��
        }
        return nums.size()-k;
    }
};

