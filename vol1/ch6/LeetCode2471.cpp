class Solution {
public:
    int minimumOperations(TreeNode* root) {
        int ans=0;
        queue<TreeNode*> qu;
        qu.push(root);                              //根结点进队
        while (!qu.empty()) {                           //队不空循环
            int n=qu.size();
            vector<int> curp;
            for(int i=0;i<n;i++) {
                TreeNode*p=qu.front(); qu.pop();           //出队一个结点p
                curp.push_back(p->val);
                if (p->left!=NULL)                      //有左孩子时将其进队
                    qu.push(p->left);
                if (p->right!=NULL)                     //有右孩子时将其进队
                    qu.push(p->right);
            }
            ans+=minswaps(curp);
        }
        return ans;
    }

    int minswaps(vector<int> &a) {				//求a变为有序的最少交换次数
        vector<int> b = a;
        sort(b.begin(), b.end());
        unordered_map<int, int> hmap;          //记录排好序的元素位置
        for (int i=0;i<b.size();i++) hmap[b[i]]=i;
        int cnt=0;
        for (int i=0;i<a.size();i++) {
            while (a[i]!=b[i]) {            				//注意这里可能需要多次交换
                swap(a[i], a[hmap[a[i]]]);
                cnt++;
            }
        }
        return cnt;
    }
};

