class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> hmap;            //定义一个哈希映射
        for(int i=0;i<nums.size();i++) {
            if(hmap.count(target-nums[i])!=0)   //在hmap中找到target-nums[i]
                return {hmap[target-nums[i]],i};    //返回结果
            hmap[nums[i]]=i;                    //将nums[i]的索引添加到hmap中
        }
        return {0,0};                           //为了满足语法
    }
};

