struct Cmp {
    bool operator() (const string&x,const string&y) {
        return x+y<y+x;							//��x+yԽ��Խ���ȳ���
    }
};
class Solution {
public:
    string largestNumber(vector<int>& nums) {
        priority_queue<string,vector<string>,Cmp> maxpq;
        for(int i=0;i<nums.size();i++)
            maxpq.push(to_string(nums[i]));
        string ans="";
        while(!maxpq.empty()) {
            ans+=maxpq.top();
            maxpq.pop();
        }
        if(ans[0]=='0') return "0";
        else return ans;
    }
};

