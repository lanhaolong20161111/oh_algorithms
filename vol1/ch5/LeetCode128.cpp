class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> hset;
        for(int x:nums)            //��ȫ��������ŵ�hset��
            hset.insert(x);
        int ans=0;                  //��Ŵ�
        for(int x:hset) {
            if(hset.find(x-1)==hset.end()) {    //��x������������ǰ��
                int y=x;                        //��xΪ������ö��
                while(hset.find(y+1)!=hset.end()) y++;
                ans=max(ans,y-x+1);             //����󳤶�
            }
        }
        return ans;
    }
};

