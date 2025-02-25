class Solution {
    vector<string> ans;
    unordered_map<char,string> hmap={{'2',"abc"},{'3',"def"},{'4',"ghi"},
        {'5',"jkl"},{'6',"mno"},{'7',"pqrs"},{'8',"tuv"},{'9',"wxyz"}};     //ӳ���
public:
    vector<string> letterCombinations(string digits) {
        int n=digits.size();
        if(n==0) return {};
        string x="";
        dfs(digits,x,0);
        return ans;
    }
    void dfs(string&digits,string&x,int i) {		//�����㷨
        if(i>=digits.size())
            ans.push_back(x);
        else {
            string key=hmap[digits[i]];      //��ȡӳ����ĸ
            for (int j=0;j<key.size();j++) {
                x.push_back(key[j]);
                dfs(digits,x,i+1);
                x.pop_back();               //����
            }
        }
    }
};

