class Solution {
public:
    bool canJump(vector<int>& nums) {
        return dfs(nums,nums.size()-1);
    }
    bool dfs(vector<int> &nums,int i) {    //�����㷨
        if(i==0) return true;
        else {
            for(int j=i-1;j>=0; j--) {		//��̽λ��i-1��0
                if(j+nums[j]>=i)       //��λ��j��������λ��i
                    return dfs(nums,j);
            }
        }
        return false;
    }
};

