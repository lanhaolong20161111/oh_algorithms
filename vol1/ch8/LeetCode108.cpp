class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return preorder(nums,0,nums.size()-1);
    }

    TreeNode* preorder(vector<int>&nums,int low,int high) {
        if(low>high) return NULL;
        int mid=(low+high)/2;
        TreeNode*root=new TreeNode(nums[mid]);
        root->left=preorder(nums,low,mid-1);
        root->right=preorder(nums,mid+1,high);
        return root;
    }
};

