class Solution {
public:
	bool isSubtree(TreeNode*root,TreeNode*subRoot) {
		if(root==NULL)
            	return false;
        	if(same(root, subRoot))
            	return true;
        	if(isSubtree(root->left,subRoot ))
            	return true;
        	else if(isSubtree(root->right,subRoot))
            	return true;
        	else
            	return false;
    	}
   	bool same(TreeNode* r1,TreeNode* r2) {     //判断r1和r2两棵二叉树是否相同
		if(r1==NULL && r2==NULL)
            	return true; 
        	if(r1==NULL || r2==NULL)
            	return false;
        	if(r1->val!=r2->val)
            	return false;
        	return same(r1->left,r2->left) & same(r1->right,r2->right);
    	}
};

