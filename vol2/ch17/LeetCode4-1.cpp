class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m=nums1.size(),n=nums2.size();
        vector<int> c;
        for(int x:nums1) c.push_back(x);
        for(int x:nums2) c.push_back(x);
        sort(c.begin(),c.end());
        int k=(m+n)/2;
        if ((m+n)%2==0)                 //��Ԫ�ظ���Ϊż�������
            return (c[k-1]+c[k])/2.0;
        else                            //��Ԫ�ظ���Ϊ���������
            return c[k];
    }
};

