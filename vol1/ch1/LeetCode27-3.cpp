class Solution {
public:
    int removeElement(vector<int>& nums,int val) {
        int j=-1;
        for(int i=0;i<nums.size();i++) {
            if (nums[i]!=val) {              //nums[i]Ϊ������Ԫ��
                j++;                         //������Ԫ������
                if (j!=i)                   //���i��j������Ԫ�ؽ���
                    swap(nums[i],nums[j]); 
            }
        }
        return j+1;                      //�����鳤��Ϊj+1
    }
};

