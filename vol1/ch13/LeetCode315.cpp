#define lowbit(x) ((x)&-(x))
class BIT {                     //��״������
private:
    vector<int> tree;           //��״����Ϊtree[1..n]
    int n;
public:
    BIT(int n):n(n),tree(n+1,0) {}
    void UpdateOne(int i,int x) {     //�����޸�
        while (i<=n) {
            tree[i]+=x;
            i+=lowbit(i);
        }
    }
    int Sum(int i) {
        int ans=0;
        while (i>0) {
            ans+=tree[i];
            i-=lowbit(i);
        }
        return ans;
    }
};
class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
       int n=nums.size();
        unordered_map<int,int> hmap;        //��ɢ��
        set<int> tset;
        for (int x:nums) tset.insert(x);
        int idx=1;									//��Ŵ�1��ʼ
        for(int x:tset) hmap[x]=idx++;
        BIT bit(idx);
        vector<int> ans(n,0);						//��Ŵ�
        for (int j=n-1;j>=0;j--) {
            int i=hmap[nums[j]];
            bit.UpdateOne(i,1);
            if (i!=1) ans[j]=bit.Sum(i-1);
            else ans[j]=0;
        }
        return ans;
    }
};

