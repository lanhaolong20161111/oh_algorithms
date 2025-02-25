class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int max1=-1,max2=-1;
        for(int d:nums) {
            if(d>max1) {
                max2=max1;
                max1=d;
            }
            else if(d>max2) {
                max2=d;
            }
        }
        return (max1-1)*(max2-1);
    }
};

