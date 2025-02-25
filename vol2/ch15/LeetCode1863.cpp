class Solution {
public:
    int subsetXORSum(vector<int>& nums) {
        int n=nums.size();
        int ans=0;
        for(int V=0;V<=(1<<n)-1;V++) {
            int curs=0;
            for(int j=0;j<n;j++) {
                if(inset(V,j)) curs^=nums[j];
            }
            ans+=curs;
        }
        return ans;
    }
    bool inset(int V,int j) {       //判断下标j是否在V中
        return (V & (1<<j))!=0;
    }
};

