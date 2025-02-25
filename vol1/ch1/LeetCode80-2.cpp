class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n=nums.size();
        if (n<=2) return n;
        int k=0;
        for (int i=2;i<n;i++) {
            if (!(nums[i-k-2]==nums[i-k-1] && nums[i]==nums[i-k-1]))
                nums[i-k]=nums[i];
            else
                k++;
        }
        return n-k;
    }
};

