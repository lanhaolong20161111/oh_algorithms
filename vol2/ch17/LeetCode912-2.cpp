class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        mergesort(nums,0,nums.size()-1);
        return nums;
    }
    void mergesort(vector<int>&a,int low,int high) {		//二路归并排序
        if(low<high) {
            int mid=(low+high)/2;
            mergesort(a,low,mid);
            mergesort(a,mid+1,high);
            merge(a,low,mid,high);
        }
    }
    void merge(vector<int>&a,int low,int mid,int high) {	//二路归并
        vector<int> tmp;
        int i=low,j=mid+1;
        while(i<mid+1 && j<high+1) {
            if(a[i]<a[j]) {
                tmp.push_back(a[i]);
                i++;
            }
            else {
                tmp.push_back(a[j]);
                j++;
            }
        }
        while(i<mid+1) {
            tmp.push_back(a[i]);
            i++;
        }
        while(j<high+1) {
            tmp.push_back(a[j]);
            j++;
        }
        j=0;
        for(int i=low;i<high+1;i++) {
            a[i]=tmp[j];
            j++;
        }
    }
};

