class Solution {
public:
    void rotate(vector<int>& nums,int k) {
        int n=nums.size();
        if(n==1) return;
        k=k%n;
        reverse(nums,0,n-k-1);
        reverse(nums,n-k,n-1);
        reverse(nums,0,n-1);
    }

    void reverse(vector<int>&nums,int s,int t) {
        int i=s,j=t;
        while(i<j) {
            swap(nums[i],nums[j]);
            i++; j--;
        }
    }
};

