class Solution {
	int ans=0;						//��Ŵ�
public:
	int reversePairs(vector<int>& nums) {
		mergesort(nums,0,nums.size()-1);
        	return ans;
    	}
    	void mergesort(vector<int>& a,int low,int high) {    //��·�鲢����
     	if(low==high) return;
        	int mid=(low+high)/2;
        	mergesort(a,low,mid);                            //a[low..mid]����
       	mergesort(a,mid+1,high);                     //a[mid+1..high]����
        	int j=mid+1;                                        //�ϲ�֮ǰ��ת��
        	for(int i=low;i<=mid;i++) {
         		for(;j<=high && (a[i]>2*(long long)a[j]);j++);
             	ans+=(j-mid-1);
       	}
        	sort(a.begin()+low,a.begin()+high+1);  //�ϲ�����
   	}
};

