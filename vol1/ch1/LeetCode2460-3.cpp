class Solution {
public:
    vector<int> applyOperations(vector<int>& nums) {
        int n=nums.size();
        int j=-1;
        for (int i=0;i<n;i++) {
            if (nums[i]==0)       //����0Ԫ��
                continue;
            else {
                if (i<n-1 && nums[i]==nums[i+1]) {
                    nums[i+1]=0;    //�޸Ĳ���
                    nums[i]*=2;
                }
                j++;                   //����0Ԫ��nums[i]�Ƶ���������
                if(j!=i)
                    swap(nums[i],nums[j]); 
            }
        }
        for(int i=j+1;i<n;i++)        //ĩβ��0
            nums[i]=0;
        return nums;
    }
};

