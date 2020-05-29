题目描述
从上往下打印出二叉树的每个节点，同层节点从左至右打印。
class Solution {//层次遍历
public:
    vector<int> PrintFromTopToBottom(TreeNode* root) {
        vector<int>res;
        if(!root) return res;
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            int n=q.size();
            for(int i=0;i<n;i++){
                TreeNode*tmp=q.front();
                q.pop();
                res.push_back(tmp->val);
                if(tmp->left) q.push(tmp->left);
                if(tmp->right) q.push(tmp->right);
            }
        }
        return res;
    }
};
