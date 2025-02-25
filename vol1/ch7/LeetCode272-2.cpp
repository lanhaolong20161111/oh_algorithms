class Solution {
public:
    vector<int> closestKValues(TreeNode* root,double target,int k) {
        queue<int> qu;
        inorder(qu,root,target,k);
        vector<int> ans;
        while(!qu.empty()) {
            ans.push_back(qu.front());
            qu.pop();
        }
        return ans;
    }

    void inorder(queue<int>&qu,TreeNode*root,double target,int k) {
        if(root!=NULL) {
            inorder(qu,root->left,target,k);
            if(qu.size()==k) {
                if(abs(qu.front()-target)>abs(root->val-target)) {
                    qu.pop();
                    qu.push(root->val);
                }
                else return;
            }
            else qu.push(root->val);
            inorder(qu,root->right,target,k);
        }
    }
};

