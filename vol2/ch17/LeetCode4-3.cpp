class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m=nums1.size(),n=nums2.size();
        int k=(m+n)/2;
        if ((m+n)%2==0) {                                   //总元素个数为偶数的情况
            int mid1=Findk(nums1,nums2,k);
            int mid2=Findk(nums1,nums2,k+1);
            return (mid1+mid2)/2.0;
        }
        else  return Findk(nums1,nums2,k+1);        //总元素个数为奇数的情况
    }
    int Findk(vector<int>& a,vector<int>& b,int k) {		//在a,b升序数组中求第k小元素
        int m=a.size(),n=b.size();
        int i=0,j=0;                                            //i和j分别遍历a和b的指针
        while (k>1) {                                           //循环直到k缩小为1
            int av=i+k/2-1<m?a[i+k/2-1]:INT_MAX;
            int bv=j+k/2-1<n?b[j+k/2-1]:INT_MAX;
            if (av<bv) i+=k/2;
            else j+=k/2;
            k-=k/2;                                             //每次循环k递减k/2
        }
        if(i>=m) return b[j+k-1];                //若a空，直接返回b中的第k小元素
        if(j>=n) return a[i+k-1];                //若b空，直接返回a中的第k小元素
        return min(a[i], b[j]);                             //两数组均不为空(k==1)，返回最小值
    }
};

