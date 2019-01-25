题目描述
从上到下按层打印二叉树，同一层结点从左至右输出。每一层输出一行。
层次遍历
class Solution {
public:
        vector<vector<int> > Print(TreeNode* pRoot) {
            vector<vector<int> >res;
            if(!pRoot) return res;
            queue<TreeNode*>q;
            q.push(pRoot);
            while(!q.empty()){
                int n=q.size();
                vector<int>node;
                for(int i=0;i<n;i++){
                    TreeNode*tmp=q.front();
                    q.pop();
                    node.push_back(tmp->val);
                    if(tmp->left) q.push(tmp->left);
                    if(tmp->right) q.push(tmp->right);
                }
                res.push_back(node);
            }
            return res;
        }
};
