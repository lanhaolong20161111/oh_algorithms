class Solution {
public:
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        unordered_map<int,TreeNode*> hmap;
        TreeNode *root=NULL;
        for(vector<int>&v:descriptions)
            hmap[v[1]]=new TreeNode(v[1]);  //创建所有的子结点
        for(vector<int>&v:descriptions) {
            if(hmap.count(v[0])==0) {       //找根结点
                hmap[v[0]]=new TreeNode(v[0]);
                root=hmap[v[0]];
            }
            if(v[2]==1)                     //建立父子关系
                hmap[v[0]]->left=hmap[v[1]];
            else
                hmap[v[0]]->right=hmap[v[1]];
        }
        return root;
    }
};

