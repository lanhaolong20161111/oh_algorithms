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
            if(presum%2==0) {      //ǰ׺��Ϊż��ʱ
                ans=(ans+odd)%MOD;
                even++;
            }
            else {              			//ǰ׺��Ϊ����ʱ
                ans=(ans+even)%MOD;
                odd++;
            }
        }
        return ans;
    }
};

