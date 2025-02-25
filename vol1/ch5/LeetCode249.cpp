class Solution {
public:
    vector<vector<string>> groupStrings(vector<string>& strings) {
        string key;
        unordered_map<string,vector<string>> hmap;
        for(string x:strings) {
            key="";
            for(int i=1;i<x.size();i++)
                key+=(x[i]-x[0]+26)%26;     //��ǰ�ַ������ַ��ľ���
            hmap[key].push_back(x);
        }
        vector<vector<string>> ans;         //��Ŵ�
        for(auto x:hmap) {
            ans.push_back(x.second);
        }
        return ans;
    }
};

