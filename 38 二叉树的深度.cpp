class Solution {//递归
public:
    int TreeDepth(TreeNode* pRoot)
    {
        if(!pRoot) return 0;//初始条件
        return max(TreeDepth(pRoot->left),TreeDepth(pRoot->right))+1;//+1蕴含了迭代关系
    }
};


class Solution {//非递归。实际是层次遍历，每通过一层增加一个深度。也就是Breadth-First Search（BFS），广度优先
public://延伸：二叉树深度优先遍历和广度优先遍历 - zhangbaochong - 博客园 https://www.cnblogs.com/zhangbaochong/p/5492877.html
    int TreeDepth(TreeNode* pRoot)
    {
        if(!pRoot) return 0;
        int res=0;
        queue<TreeNode*>q;
        q.push(pRoot);
        while(!q.empty()){
            int n=q.size();
            for(int i=0;i<n;i++){
                TreeNode*tmp=q.front();
                q.pop();
                if(tmp->left) q.push(tmp->left);
                if(tmp->right) q.push(tmp->right);
            }
            res++;
        }
        return res;
    }
};
知识点：广度优先搜索（bfs）即层次遍历，使用队列；
       深度优先搜索（dfs），如前序遍历，使用栈。
