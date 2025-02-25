class Solution {
    unordered_map<char,string> hmap={{'2',"abc"},{'3',"def"},{'4',"ghi"},
        {'5',"jkl"},{'6',"mno"},{'7',"pqrs"},{'8',"tuv"},{'9',"wxyz"}};     //”≥…‰±Ì
public:
    vector<string> letterCombinations(string digits) {
        int n=digits.size();
        if(n==0) return {};
        vector<string> ans;
        if(n==1) {
            string key=hmap[digits[0]];
            for (char c:key) {
                ans.push_back(string(1,c));
            }
            return ans;
        }
        vector<string> subs=letterCombinations(digits.substr(1));
        string key=hmap[digits[0]];
         for (string e:subs) {
            for (char c:key)
                ans.push_back(string(1,c)+e);
        }
        return ans; 
    }
};

