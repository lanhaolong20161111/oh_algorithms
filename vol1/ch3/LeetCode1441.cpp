class Solution {
public:
    vector<string> buildArray(vector<int>& target,int n) {
        vector<string> ans;
        int j=0;                            //遍历target数组
        for(int i=1;i<=n;i++) {
            ans.push_back("Push");          //i进栈
            if (i!=target[j])               //target数组的当前元素不等于i
                ans.push_back("Pop");       //出栈i
            else                            //target数组的当前元素等于i
                j++;
            if (j==target.size())           //target数组遍历完时退出循环
                break;
        }
        return ans;        
    }
};

