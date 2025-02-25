#define lowbit(x) ((x)&-(x))
class BIT {
    vector<int> tree;                       //树状数组为tree[1..n]
    int n;
public:
    BIT(int n):n(n),tree(n+1,0) {}
    void UpdateOne(int i,int x) {           //单点修改
        while (i<=n) {
            tree[i]+=x;
            i+=lowbit(i);
        }
    }    
    int Sum(int i) {                        //求前缀和
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
    int kEmptySlots(vector<int>& bulbs,int k) {
        int n=bulbs.size();
        vector<bool> open(n+1,false);
        BIT bit=BIT(n);
        for(int i=0;i<n;i++) {
            int x=bulbs[i];     //当前位置是x
            int p=x+k+1;        //后面位置是x+k+1
            if(p<=n && open[p]) {
                if(bit.Sum(x+1)==bit.Sum(p)) return i+1;
            }
            p=x-k-1;            //前面位置是x+k+1
            if(p>0 && open[p]) {
                if(bit.Sum(p+1)==bit.Sum(x)) return i+1;
            }
            bit.UpdateOne(x+1,1);   //第i天打开灯泡
            open[x] = true;
        }
        return -1;
    }
};

