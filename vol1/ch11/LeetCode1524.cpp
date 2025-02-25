class Solution {
    const int MOD=1000000007;
public:
    int numOfSubarrays(vector<int>& arr) {
        int n=arr.size();
        int odd=0,even=1;
        int ans=0;
        int presum=0;
        for (int j=0;j<n;j++) {
            presum+=arr[j];
            if(presum%2==0) {      //前缀和为偶数时
                ans=(ans+odd)%MOD;
                even++;
            }
            else {              			//前缀和为奇数时
                ans=(ans+even)%MOD;
                odd++;
            }
        }
        return ans;
    }
};

