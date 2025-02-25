class Solution {
    vector<int> a;
public:
    vector<int> closestKValues(TreeNode* root, double target, int k) {
        vector<int> ans;
        inorder(root);
        int high=lower_bound(a.begin(),a.end(),target)-a.begin();
        int low=high-1;
        for(int i=0;i<k;i++) {
            if (low>=0 && high<a.size()) {
                if(abs(a[low]-target)<=abs(a[high]-target)) {
                    ans.push_back(a[low]);
                    low--;
                }
                else {
                    ans.push_back(a[high]);
                    high++;
                }
            }
            else if(low>=0) {
                ans.push_back(a[low]);
                low--;
            }
            else {
                ans.push_back(a[high]);
                high++;
            }
        }
        return ans;
    }

     void inorder(TreeNode*root) {                 //中序遍历得到a
        if(root!=NULL) {
            inorder(root->left);
            a.push_back(root->val);
            inorder(root->right);
        }
    }
};

