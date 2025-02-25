class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1,vector<int>& nums2) {
        int m=nums1.size(),n=nums2.size();
        if(m==0) return (nums2[(n+1)/2-1]+nums2[(n+2)/2-1])/2.0; 
        if(n==0) return (nums1[(m+1)/2-1]+nums1[(m+2)/2-1])/2.0; 
        int a[m],b[n];
        for(int i=0;i<m;i++) a[i]=nums1[i];
        for(int i=0;i<n;i++) b[i]=nums2[i];
        int mid1=(m+n+1)/2;
        int mid2=(m+n+2)/2;
        return (Findk(a,m,b,n,mid1)+Findk(a,m,b,n,mid2))/2.0;
    }
   int Findk(int a[],int m,int b[],int n,int k) { //在a,b升序数组中求第k小元素
        if (m>n)                  //保证前一个数组元素个数比少
            return Findk(b,n,a,m,k);
        if (m==0)
            return b[k-1];
        if (k==1)
            return ((a[0]>=b[0]) ? b[0]:a[0]);
        int i=min(m,k/2);     //当数组a中没有k/2个元素时取m
        int j=k-i; 
        if(a[i-1]==b[j-1])
            return a[i-1];
        else if(a[i-1]>b[j-1])
            return Findk(a,m,b+j,n-j,k-j);
        else                //a[i-1]<b[j-1]
            return Findk(a+i,m-i,b,n,k-i);
    }
};

