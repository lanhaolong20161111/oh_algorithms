class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        vector<vector<int>> ans;
        int n=arr.size();
        sort(arr.begin(),arr.end());
        int mind=arr[n-1]-arr[0];
        for(int i=1;i<n;i++) {
            if(arr[i]-arr[i-1]<mind) {
                mind=arr[i]-arr[i-1];
                ans.clear();
                ans.push_back({arr[i-1],arr[i]});
            }
            else if(arr[i]-arr[i-1]==mind)
                ans.push_back({arr[i-1],arr[i]});
        }
        return ans;
    }
};

