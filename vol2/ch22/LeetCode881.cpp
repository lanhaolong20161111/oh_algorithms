class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(),people.end());		//递增排序
        int i=0,j=people.size()-1;
        int ans=0;
        while(i<=j) {
            if(i==j) {      //特殊情况：剩下最后一个人单乘
                ans++;
                break;
            }
            if(people[i]+people[j]<=limit) {    //前后两个人同乘
                ans++;
                i++; j--;
            }
            else {                              //第j个人单乘
                ans++;
                j--;
            }
        }
        return ans;
    }
};

