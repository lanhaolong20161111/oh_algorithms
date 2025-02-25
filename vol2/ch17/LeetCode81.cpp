class Solution {
public:
    bool search(vector<int>& nums,int target) {
        int n=nums.size();
        int low=0,high=n-1;
        while(low<=high) {                              //��������������һ��Ԫ��ʱѭ��
            int mid=(low+high)/2;
            if (nums[mid]==target)                  //�ҵ���ֱ�ӷ���mid
                return true;
            if (nums[mid]<nums[high]) {           //nums[mid]�����������
                if (nums[mid]<=target && target<=nums[high])
                    low=mid+1;                      //������κ��沿��(����)�в���
                    else
                        high=mid-1;                     //��nums[low..mid-1]�в���
            }
            else if (nums[mid]>nums[high]) {    //nums[mid]�����������
                if (nums[low]<=target && target<=nums[mid])
                    high=mid-1;                     //���������ǰ�沿��(����)�в���
                    else
                    low=mid+1;                      //��nums[mid+1..high]�в���
            }
            else                                //nums[mid]=nums[high])
                high--;                                 //���������Ҷ���Сһ��λ��
        }
        return false;
    }
};

