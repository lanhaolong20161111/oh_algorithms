class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        vector<int> ins;
        ListNode*p=head;
        while(p!=NULL) {
            ins.push_back(p->val);
            p=p->next;
        }
        return preorder(ins,0,ins.size()-1);        
    }
    
    TreeNode* preorder(vector<int>&ins,int low,int high) {
        if(low>high) return NULL;
        int mid=(low+high)/2;
        TreeNode*root=new TreeNode(ins[mid]);
        root->left=preorder(ins,low,mid-1);
        root->right=preorder(ins,mid+1,high);
        return root;
    }
};

