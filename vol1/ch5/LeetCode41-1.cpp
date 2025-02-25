class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        unordered_set<int> hset;
        for(int x:nums) hset.insert(x);
        int ans=1;
        while(ans<=nums.size()+1) {
            if(hset.find(ans)==hset.end())
                break;
            ans++;
        }
        return ans;
    }
};

