class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> hset;
        for(int x:nums)            //将全部整数存放到hset中
            hset.insert(x);
        int ans=0;                  //存放答案
        for(int x:hset) {
            if(hset.find(x-1)==hset.end()) {    //若x不存在连续的前驱
                int y=x;                        //以x为起点向后枚举
                while(hset.find(y+1)!=hset.end()) y++;
                ans=max(ans,y-x+1);             //求最大长度
            }
        }
        return ans;
    }
};

