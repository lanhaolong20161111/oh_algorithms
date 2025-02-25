class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> hmap;            //����һ����ϣӳ��
        for(int i=0;i<nums.size();i++) {
            if(hmap.count(target-nums[i])!=0)   //��hmap���ҵ�target-nums[i]
                return {hmap[target-nums[i]],i};    //���ؽ��
            hmap[nums[i]]=i;                    //��nums[i]��������ӵ�hmap��
        }
        return {0,0};                           //Ϊ�������﷨
    }
};

