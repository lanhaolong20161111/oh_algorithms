class Solution {
public:
    int shipWithinDays(vector<int>& weights,int D) {    //���ҵ��������һ��Ԫ��
        int maxw,sum=0;
        maxw=weights[0];
        for(int e:weights) {     //��weights�����ֵmaxw��Ԫ�غ�sum
            maxw=max(maxw,e);
            sum+=e;
        }
        int low=maxw,high=sum;
        while(low<high) {
            int mid=(low+high)/2;
            int cnt=Count(weights,mid);
            if(cnt<D)          //˵��mid����
                high=mid;       //���������м�������
            else                //˵��midС��
                low=mid+1;     //���������м�������
        }
        return low;
    }
    int Count(vector<int>& weights,int mid) {
        int cursum=0,cnt=0;
        for(int i=0;i<weights.size();i++) { //����midΪ��������ʱ��Ӧ������cnt
            cursum+=weights[i];
            if(cursum>mid) {
                cnt++;
                cursum=weights[i];
            }
        }
        return cnt;
    }
};

