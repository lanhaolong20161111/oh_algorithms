class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        quicksort(nums,0,nums.size()-1);
        return nums;
    }
    vector<int> partition2(vector<int>&a,int s,int t) { //划分算法2（用于递增排序）
    int base=a[(s+t)/2];
    int i=s,j=t;
    while(i<=j) {
        while (i<=j && a[i]<base) i++;      //从左向右跳过小于base的元素
        while (i<=j && a[j]>base) j--;      //从右向左跳过大于base的元素
        if(i<=j) {
            swap(a[i],a[j]);                    //a[i]和a[j]交换
            i++;j--;
        }
    }
    return {j,i};
    }
    void quicksort(vector<int>&a,int s,int t) { //快速排序
        if(s<t) {
            vector<int> p=partition2(a,s,t); 
            quicksort(a,s,p[0]);
            quicksort(a,p[1],t);
        }
    }
};

