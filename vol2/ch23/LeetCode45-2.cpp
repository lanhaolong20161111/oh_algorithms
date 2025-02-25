class Solution {
public:
    	int jump(vector<int>& nums) {
        	int n=nums.size();
        	if(n==1) return 0;
        	int i=0,steps=0;
        	while(i<n-1) {
            	int end=i+nums[i];
            	if(end>=n-1) {						//��λ��i���������յ�
                	steps++; break;
            	}
            	int maxj=i+1;
            	for(int j=i+2;j<=end;j++) {		//��maxj={j|j+nums[j]���j����[i+1,end]
                	if(j+nums[j]>maxj+nums[maxj]) maxj=j;
           	}
            	i=maxj;									//��λ��i����λ��maxj
            	steps++;									//��Ծ������1
        	}
        	return steps;
    }
};

