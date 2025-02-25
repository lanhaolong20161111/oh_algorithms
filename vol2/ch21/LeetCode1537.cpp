typedef long long LL;
class Solution {
private:
    const int mod=1000000007;
public:
    int maxSum(vector<int>& nums1,vector<int>& nums2) {
        int m=nums1.size(),n=nums2.size();
        LL dp1=0,dp2=0;
        int i=1,j=1;
        while(i<=m && j<=n) {
            if (nums1[i-1]<nums2[j-1]) {
                dp1=dp1+nums1[i-1];
                i++;
            }
            else if(nums1[i-1]>nums2[j-1]) {
                dp2=dp2+nums2[j-1];
                j++;
            }
            else {
                LL cmax=max(dp1,dp2)+nums1[i-1];
                dp1=dp2=cmax;
                i++;j++;
            }
        }
        while (i<=m) {
            dp1=dp1+nums1[i-1];
            i++;
        }
        while (j<=n) {
            dp2=dp2+nums2[j-1];
            j++;
        }
        return max(dp1,dp2) % mod;
    }
};

