class Solution {
public:
    int subarraySum(vector<int>& nums,int k) {
        unordered_map<int,int> hmap;
        hmap[0]=1;
        int presum=0,ans=0; 
        for (int j=0;j<nums.size();j++){
            presum+=nums[j];
            int rest=presum-k;
            if (hmap.count(rest)>0) 
                ans+=hmap[rest]; 
            hmap[presum]++;
        } 
        return ans; 
    }  
};

