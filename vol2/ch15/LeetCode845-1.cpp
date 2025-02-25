class Solution {
public:
    int longestMountain(vector<int>& arr) {
        int n=arr.size();
        if (n<3) return 0;
        int ans=0;
        for (int i=1;i<n-1;i++) {
            int cur=center(arr,i);
            ans=max(ans,cur);
        }
        return ans;
    }
    int center(vector<int>&a,int i) {
        int left=0;
        for(int j=i-1;j>=0;j--) {
            if(a[j]<a[j+1]) left++;
            else break;
        }
        int right=0;
        for(int j=i+1;j<a.size();j++) {
            if(a[j-1]>a[j]) right++;
            else break;
        }
        if(left>0 && right>0)
            return left+right+1;
        return 0;
    }
};

