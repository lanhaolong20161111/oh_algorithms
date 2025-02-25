class Solution {
public:
	vector<bool> checkIfPrerequisite(int n,vector<vector<int>>&prereqs,vector<vector<int>>&ques) {
    	vector<vector<bool>> A(n,vector<bool>(n,false));
        for (auto e: prereqs) {
            int a=e[0],b=e[1];
            A[a][b]=true;
        }
        for(int k=0;k<n;k++) {
            for(int i=0;i<n;i++) {
                for(int j=0;j<n;j++) {
                    A[i][j]=A[i][j] | (A[i][k] && A[k][j]);
                }
            }
        }
        vector<bool> ans;
        for (auto e:ques) {
            int u=e[0],v=e[1];
            ans.push_back(A[u][v]);
        }
        return ans;
    }
};

