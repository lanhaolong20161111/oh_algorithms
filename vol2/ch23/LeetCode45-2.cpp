class Solution {
public:
    	int jump(vector<int>& nums) {
        	int n=nums.size();
        	if(n==1) return 0;
        	int i=0,steps=0;
        	while(i<n-1) {
            	int end=i+nums[i];
            	if(end>=n-1) {						//从位置i可以跳到终点
                	steps++; break;
            	}
            	int maxj=i+1;
            	for(int j=i+2;j<=end;j++) {		//求maxj={j|j+nums[j]最大，j属于[i+1,end]
                	if(j+nums[j]>maxj+nums[maxj]) maxj=j;
           	}
            	i=maxj;									//从位置i跳到位置maxj
            	steps++;									//跳跃次数增1
        	}
        	return steps;
    }
};

