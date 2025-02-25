class Solution {
	int ans=0;						//存放答案
public:
	int reversePairs(vector<int>& nums) {
		mergesort(nums,0,nums.size()-1);
        	return ans;
    	}
    	void mergesort(vector<int>& a,int low,int high) {    //二路归并排序
     	if(low==high) return;
        	int mid=(low+high)/2;
        	mergesort(a,low,mid);                            //a[low..mid]排序
       	mergesort(a,mid+1,high);                     //a[mid+1..high]排序
        	int j=mid+1;                                        //合并之前求翻转对
        	for(int i=low;i<=mid;i++) {
         		for(;j<=high && (a[i]>2*(long long)a[j]);j++);
             	ans+=(j-mid-1);
       	}
        	sort(a.begin()+low,a.begin()+high+1);  //合并操作
   	}
};

