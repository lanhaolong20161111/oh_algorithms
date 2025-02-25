class Solution {
public:
    vector<int> sortedSquares(vector<int>&nums) {
        int n=nums.size();
        for(int i=0;i<n;i++)
            nums[i]=nums[i]*nums[i];
        int mind=nums[0],mini=0;
        for(int i=1;i<n;i++) {
            if(nums[i]<mind){
                mind=nums[i];
                mini=i;
            }
        }
        vector<int> ans(n,0);				//存放答案
        int k=0;								//累计归并的元素个数
        ans[k++]=mind;
        int i=mini-1,j=mini+1;
        while(i>=0 && j<n){
            if(nums[i]<=nums[j]){
                ans[k]=nums[i];
            	i--; k++;
            }
            else{
                ans[k]=nums[j];
           	 j++; k++;
            }
        }
        while(i>=0){			//左边序列没有归并完时
            ans[k]=nums[i];
        i--;k++;
        }
        while(j<n){			//右边序列没有归并完时
            ans[k]=nums[j];
            j++;k++;
        }
        return ans;
    }
};
