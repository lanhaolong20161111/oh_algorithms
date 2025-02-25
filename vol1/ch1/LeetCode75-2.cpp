class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n=nums.size();
        vector<int> x(3,0);
        for(int i=0;i<n;i++)
            x[nums[i]]++;
        int k=0;
        for(int i=0;i<3;i++) {
            for(int j=0;j<x[i];j++)
                nums[k++]=i;
        }
    }
};

