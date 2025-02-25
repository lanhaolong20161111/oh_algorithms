class Solution {
public:
    TreeNode* reverseOddLevels(TreeNode* root) {
        if(root->left==NULL && root->right==NULL)
            return root; 
        queue<TreeNode*> qu;
        qu.push(root);                              //根结点进队
        int curl=0;
        while (!qu.empty()) {                           //队不空循环
            int n=qu.size();
            vector<TreeNode*> curp;
            for(int i=0;i<n;i++) {
                TreeNode*p=qu.front(); qu.pop();           //出队一个结点p
                curp.push_back(p);
                if (p->left!=NULL)                      //有左孩子时将其进队
                    qu.push(p->left);
                if (p->right!=NULL)                     //有右孩子时将其进队
                    qu.push(p->right);
            }
            if(curl%2==1) rev(curp);
            curl++;
        }
        return root;
    }

    void rev(vector<TreeNode*> &a) {			//反转a
        int i=0,j=a.size()-1;
        while(i<j) {
            swap(a[i]->val,a[j]->val);
            i++; j--;
        }
    }
};

