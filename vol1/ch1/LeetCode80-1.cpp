class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n=nums.size();
        if (n<=2) return n;
        int k=2;
        for (int i=2;i<n;i++) {
            if (!(nums[k-2]==nums[k-1] && nums[i]==nums[k-1])) {
                nums[k]=nums[i];                    //nums[i]Îª±£ÁôÔªËØ
                k++;
            }
        }
        return k;
    }
};

