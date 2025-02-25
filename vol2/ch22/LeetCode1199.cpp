class Solution {
public:
    int minBuildTime(vector<int>& blocks,int split) {
        priority_queue<int,vector<int>,greater<>> pqu;  		//Ð¡¸ù¶Ñ
        int n=blocks.size();
        if(n==1) return blocks[0];
        for(int i=0;i<n;i++)
            pqu.push(blocks[i]);
        while (pqu.size()>1) {
            int x=pqu.top();pqu.pop();
            int y=pqu.top();pqu.pop();
            pqu.push(split+max(x,y));
        }
        return pqu.top();
    }
};

