class Solution {
public:
    string removeDuplicates(string s) {
        deque<char> dq;
        for(int i=0;i<s.size();i++) {
            if (!dq.empty() && dq.back()==s[i])
                dq.pop_back();
            else
                dq.push_back(s[i]);
        }
        string ans="";
        while(!dq.empty()) {
            ans.push_back(dq.front());
            dq.pop_front();
        }
        return ans;
    }
};

