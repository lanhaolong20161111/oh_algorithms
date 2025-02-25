class Solution {
public:
    vector<string> letterCombinations(string digits) {
        int n=digits.size();
        if(n==0) return {};
        unordered_map<char,string> hmap={{'2',"abc"},{'3',"def"},{'4',"ghi"},
                  {'5',"jkl"},{'6',"mno"},{'7',"pqrs"},{'8',"tuv"},{'9',"wxyz"}};   //”≥…‰±Ì
        vector<string> ans={""};
        for (int i=0;i<n;i++) {
            string curd=hmap[digits[i]];
            vector<string> ans1=ans;
            ans.clear();
            for (string x1:ans1) {
                for (char y1:curd) {
                    ans.push_back(x1+y1);
                }
            }
        }
        return ans;
    }
};

