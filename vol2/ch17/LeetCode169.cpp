class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n=nums.size();
        if(n==1) return nums[0];
        return majore(nums,0,n-1);
    }
    int majore(vector<int> &nums,int low,int high) {
        if(low==high)
            return nums[low];
        int mid=(low+high)/2;
        int leftmaj=majore(nums,low,mid);
        int rightmaj=majore(nums,mid+1,high);
        if(leftmaj==rightmaj)
            return leftmaj;
        else {
            int leftcnt=0;
            for(int i=low;i<=high;i++)
                if(nums[i]==leftmaj) leftcnt++;
            int rightcnt=0;
            for(int i=low;i<=high;i++)
                if(nums[i]==rightmaj) rightcnt++;
            if(leftcnt>rightcnt)
                return leftmaj;
            else
                return rightmaj;
        }
    }
};

