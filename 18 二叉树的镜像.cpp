题目描述
操作给定的二叉树，将其变换为源二叉树的镜像。
class Solution {
public:
    void Mirror(TreeNode *pRoot) {
        if(!pRoot) return;
        Mirror(pRoot->right);
        Mirror(pRoot->left);
        TreeNode*tmp=pRoot->left;
        pRoot->left=pRoot->right;
        pRoot->right=tmp;
    }
};

class Solution {//非递归，层次遍历
public:
    void Mirror(TreeNode *pRoot) {
        if(!pRoot) return;
        queue<TreeNode*>q;
        q.push(pRoot);
        while(!q.empty()){
            int n=q.size();
            for(int i=0;i<n;i++){
                TreeNode*cur=q.front();
                q.pop();
                TreeNode*tmp=cur->left;
                cur->left=cur->right;
                cur->right=tmp;
                if(cur->left) q.push(cur->left);
                if(cur->right) q.push(cur->right);
            }
        }
    }
};
