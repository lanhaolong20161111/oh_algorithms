class Solution {
public:
    int maxSubArrayLen(vector<int>& nums,int k) {
        unordered_map<long,long> hmap;
        hmap[0]=-1;
        long presum=0,ans=0; 
        for (int j=0;j<nums.size();j++){
            presum+=nums[j];
            long rest=presum-k;
            if (hmap.count(rest)>0) 
                ans=max(ans,j-hmap[rest]); 
            if(hmap.count(presum)==0)
                hmap[presum]=j;
        } 
        return ans; 
    }
};

