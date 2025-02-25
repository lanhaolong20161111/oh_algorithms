class Solution {
public:
    int maxNumberOfApples(vector<int>& weight) {
        int n=weight.size();
        sort(weight.begin(),weight.end());  //µ›‘ˆ≈≈–Ú
        int ans=0;
        int r=5000;
        for(int i=0;i<n;i++) {
            if(weight[i]<=r) {
                ans++;
                r-=weight[i];
            }
            else break;
        }
        return ans;
    }
};

