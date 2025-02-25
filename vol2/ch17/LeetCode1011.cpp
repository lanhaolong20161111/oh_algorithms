class Solution {
public:
    int shipWithinDays(vector<int>& weights,int D) {    //查找到区间仅含一个元素
        int maxw,sum=0;
        maxw=weights[0];
        for(int e:weights) {     //求weights中最大值maxw和元素和sum
            maxw=max(maxw,e);
            sum+=e;
        }
        int low=maxw,high=sum;
        while(low<high) {
            int mid=(low+high)/2;
            int cnt=Count(weights,mid);
            if(cnt<D)          //说明mid大了
                high=mid;       //在左区间中继续查找
            else                //说明mid小了
                low=mid+1;     //在右区间中继续查找
        }
        return low;
    }
    int Count(vector<int>& weights,int mid) {
        int cursum=0,cnt=0;
        for(int i=0;i<weights.size();i++) { //求以mid为运载能力时对应的天数cnt
            cursum+=weights[i];
            if(cursum>mid) {
                cnt++;
                cursum=weights[i];
            }
        }
        return cnt;
    }
};

