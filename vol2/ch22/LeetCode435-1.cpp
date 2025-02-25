struct Cmp {
  bool operator()(const vector<int>&a, const vector<int>&b) {
      return a[1]<b[1];                 //用于按右端点递增排序
    }
};
class Solution {
public:
  int eraseOverlapIntervals(vector<vector<int>>& intervals) {
      int n=intervals.size();
      if(n<=1) return 0;
      sort(intervals.begin(),intervals.end(),Cmp());
      int ans=1;                           //表示兼容区间的个数，初始为1
      int preend=intervals[0][1];           //存放区间0的右端点
      for (int i=1;i<n;i++) {               //遍历intervals
          if (intervals[i][0]>=preend) {        //当前区间是兼容区间(不重叠)
            ans++;
              preend=intervals[i][1];
          }
        }
        return n-ans;
    }
};

