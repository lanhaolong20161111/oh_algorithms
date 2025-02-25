class Solution {
public:
    int findKthLargest(vector<int>& nums,int k) {
        int n=nums.size();
        return quickselect(nums,0,n-1,k);
    }
    int quickselect(vector<int>&a,int s,int t,int k) {  //在a[s..t]序列中找第k大的元素
        if (s<t) {                  //区间内至少存在2个元素的情况
            int i=partition1(a,s,t);
            if (k-1==i)
                return a[i];
            else if (k-1<i)
                return quickselect(a,s,i-1,k);  //在左区间中递归查找
            else
                return quickselect(a,i+1,t,k);          //在右区间中递归查找
        }
        else return a[k-1];
    }
    int partition1(vector<int>&a,int s,int t) {          //划分算法1（用于递减排序）
	    int i=s,j=t;
    int base=a[s];                      //序列中首元素作为基准
    while(i<j) {                       //从两端交替向中间遍历,直至i=j为止
        while (i<j && a[j]<=base) 
            j--;                        //从右向左找大于base的a[j]
        if(i<j) {
            a[i]=a[j];                  //将a[j]前移到a[i]的位置
            i++;
        }
        while (i<j && a[i]>=base) 
            i++;                        //从左向右找小于base的a[i]
        if(i<j) {
            a[j]=a[i];                  //将a[i]后移到a[j]的位置
            j--;
        }
    }
    a[i]=base;
    return i;
}
};

