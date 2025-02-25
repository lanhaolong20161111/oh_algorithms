#define lowbit(x) ((x)&-(x))
typedef long long LL;
class BIT {                     //��״������
private:
    vector<int> tree;					//��״����Ϊtree[1..n]
    int n;
public:
    BIT(int n):n(n),tree(n+1,0) {}
    void UpdateOne(int i,int x) {			//�����޸�
        while (i<=n) {
            tree[i]+=x;
            i+=lowbit(i);
        }
    }
    int Sum(int i) {						//��ǰ׺��
        int ans=0;
        while (i) {
            ans+=tree[i];
            i-=lowbit(i);
        }
        return ans;
    }
};
class Solution {
public:
    int countRangeSum(vector<int>& nums,int lower,int upper) {
        int n=nums.size();
        vector<LL> presum(n+1);         //ǰ׺������
        presum[0]=0;
        for(int i=1;i<=n;i++)
            presum[i]=presum[i-1]+nums[i-1];
        set<LL> tset;                   				//����
        for (LL x:presum) {
            tset.insert(x);
            tset.insert(x-lower);
            tset.insert(x-upper);
        }
        unordered_map<LL,int> hmap;     //��ɢ��
        int idx=0;
        for(LL x:tset) {
            hmap[x]=idx++;
        }
        int ans=0;
        BIT bit(hmap.size());
        for(LL x: presum) {
            int i=hmap[x-upper],j=hmap[x-lower];
            ans+=bit.Sum(j+1)-bit.Sum(i);
            int k=hmap[x];
            bit.UpdateOne(k+1,1);
        }
        return ans;
    }
};

