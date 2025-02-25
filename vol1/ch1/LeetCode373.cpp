struct QNode {
    int i;					//表示nums1[i]的序号
    int j;					//表示nums2[j]的序号
    int sum;				//表示nums1[i]+nums2[j]
    QNode() {}
    QNode(int i,int j,int s):i(i),j(j),sum(s) {}
};
class Solution {
    const int INF=0x3f3f3f3f;
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1,vector<int>& nums2,int k) {
        int m=nums1.size();
        int n=nums2.size();
        vector<vector<int>> ans;
        vector<QNode> x(m);
        for(int i=0;i<m;i++)
            x[i]=QNode(i,0,nums1[i]+nums2[0]);
        while(k--) {
            int mini=mink(nums1,nums2,x);
            if(mini==-1) break;
            ans.push_back({nums1[x[mini].i],nums2[x[mini].j]});
            if(x[mini].j+1<n) {
                int i=x[mini].i,j=x[mini].j+1;
                x[mini]=QNode(i,j,nums1[i]+nums2[j]);
            }
            else 
                x[mini]=QNode(-1,-1,INF);
        }
        return ans;
    }
    int mink(vector<int>&a,vector<int>&b,vector<QNode>&x) {
        int mini=0;
        for(int k=1;k<x.size();k++) {
            if(x[k].sum<x[mini].sum)  mini=k;
        }
        if(x[mini].sum==INF)  return -1;
        else return mini;
    }
};

