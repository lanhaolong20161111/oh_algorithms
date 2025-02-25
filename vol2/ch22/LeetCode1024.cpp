struct Cmp {
  bool operator()(const vector<int>&a, const vector<int>&b) {
      return a[0]<b[0];           //用于按左端点递增排序
    }
};
class Solution {
public:
    int videoStitching(vector<vector<int>> &clips,int time) {
        int n=clips.size();
        sort(clips.begin(),clips.end(),Cmp());
        int ans=0;              					//存放答案
        int preend=0;           					//当前选择片段的右端点,初始看成虚拟区间[0,0]
        int i=0;
        while (preend<time) {
            int next=preend; 									//最大的右端点
            while (i<n && clips[i][0]<=preend) {    //找重叠并且最大的右端点
                next=max(next,clips[i][1]);
                i++;
            }
            ans++;              //选择最大右端点的片段
            if (next==preend)   //找不到新片段，无法合成视频
                return -1; 
            preend=next;
        }
        return ans;
    }
};

