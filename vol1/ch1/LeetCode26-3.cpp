class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int j=0;            //���ȱ���nums[0]
        for(int i=1;i<nums.size();i++) {
            if (nums[i]!=nums[j]) {              //nums[i]Ϊ������Ԫ��
                j++;                         //������Ԫ������
                if (j!=i)                   //���i��j������Ԫ�ؽ���
                    swap(nums[i],nums[j]); 
            }
        }
        return j+1;
    }
};

