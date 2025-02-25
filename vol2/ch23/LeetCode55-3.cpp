class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n=nums.size();
        if(n==1) return true;
        int i=0;
        while(i<n-1) {
            int end=i+nums[i];
            if(end==i) return false;    //若nums[i]=0则返回false
            else if(end>=n-1) return true;		//从位置i可以跳到终点，则返回true
            else {
                int maxj=i+1;
                for(int j=i+2;j<=end;j++) {
                    if(j+nums[j]>maxj+nums[maxj]) maxj=j;
                }
                i=maxj;
            }
        }
        return true;
    }
};

