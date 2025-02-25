class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m=nums1.size(),n=nums2.size();
        int k=(m+n)/2;
        if ((m+n)%2==0) {                                   //��Ԫ�ظ���Ϊż�������
            int mid1=Findk(nums1,nums2,k);
            int mid2=Findk(nums1,nums2,k+1);
            return (mid1+mid2)/2.0;
        }
        else  return Findk(nums1,nums2,k+1);        //��Ԫ�ظ���Ϊ���������
    }
    int Findk(vector<int>& a,vector<int>& b,int k) {		//��a,b�������������kСԪ��
        int m=a.size(),n=b.size();
        int i=0,j=0;                                            //i��j�ֱ����a��b��ָ��
        while (k>1) {                                           //ѭ��ֱ��k��СΪ1
            int av=i+k/2-1<m?a[i+k/2-1]:INT_MAX;
            int bv=j+k/2-1<n?b[j+k/2-1]:INT_MAX;
            if (av<bv) i+=k/2;
            else j+=k/2;
            k-=k/2;                                             //ÿ��ѭ��k�ݼ�k/2
        }
        if(i>=m) return b[j+k-1];                //��a�գ�ֱ�ӷ���b�еĵ�kСԪ��
        if(j>=n) return a[i+k-1];                //��b�գ�ֱ�ӷ���a�еĵ�kСԪ��
        return min(a[i], b[j]);                             //���������Ϊ��(k==1)��������Сֵ
    }
};

