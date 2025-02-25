class Solution {
public:
    int findMin(vector<int>& nums) {					//���ҵ��������һ��Ԫ��
        int low=0,high=nums.size()-1;
        while(low<high) {
            int mid=(low+high)/2;
            if (nums[mid]<nums[high]) high=mid;  //��������ƽ�
            else low=mid+1;             //���������в���
        }
        return nums[low];
    }
};

