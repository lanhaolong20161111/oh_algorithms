struct Cmp {
  bool operator()(const vector<int>&a, const vector<int>&b) {
      return a[0]<b[0];           //用于按左端点递增排序
    }
};
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
      int n=intervals.size();
        if (n<=1) return intervals;
        sort(intervals.begin(),intervals.end(),Cmp());
        vector<vector<int>> ans;
        ans.push_back(intervals[0]);
        for (int i=1;i<n;i++) {           //用i遍历intervals
          int curs=intervals[i][0];       //求当前区间[curs,cure)
          int cure=intervals[i][1];
          if (ans.back()[1]<curs)       //不相交
            ans.push_back({curs,cure});
          else                  //相交：合并
            ans.back()[1]=max(ans.back()[1],cure);
      }
        return ans;
    }
};

