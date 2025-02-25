class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings,int n) {
        vector<int> diff(n);
        int low,high,c;
        for(int i=0;i<bookings.size();i++) {
            low=bookings[i][0]-1;
            high=bookings[i][1]-1;
            c=bookings[i][2];
            diff[low]+=c;
            if(high+1<diff.size())
                diff[high+1]-=c;
        }
        vector<int> ans(n);
        ans[0]=diff[0];
        for (int i=1;i<n;i++) {
            ans[i]=ans[i-1]+diff[i];
        }
        return ans;
    }
};

