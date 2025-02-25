class Solution {
public:
    int longestMountain(vector<int>& arr) {
        int n=arr.size();
        if (n<3) return 0;
        vector<int> left(n);
        for (int i=1;i<n;i++) {
            if (arr[i-1]<arr[i])
                left[i]=left[i-1]+1;
            else
                left[i]=0;
        }
        vector<int> right(n);
        for (int j=n-2;j>=0;j--) {
            if(arr[j+1]<arr[j])
                right[j]=right[j+1]+1;
            else
                right[j]=0;
        }
        int ans=0;
        for (int i=0;i<n;i++) {
            if (left[i]>0 && right[i]>0)
                ans=max(ans,left[i]+right[i]+1);
        }
        return ans;
    }
};

