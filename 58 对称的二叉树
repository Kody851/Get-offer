题目描述
请实现一个函数，用来判断一颗二叉树是不是对称的。注意，如果一个二叉树同此二叉树的镜像是同样的，定义其为对称的。
@知识点：
vector<TreeNode*>().swap(array);//清空并释放内存  交换：array.swap(b);
array.clear();//以下两种都只清空，不释放内存
while(!array.empty()){
  array.pop_back（）；
}


1、递归
class Solution {
public:
    bool isSymmetrical(TreeNode* pRoot)
    {
        if(!pRoot) return true;
        return helper(pRoot->left, pRoot->right);
    }
    bool helper(TreeNode*l, TreeNode*r){
        if(!l&&!r) return true;
        else if(l&&r&&l->val==r->val) 
            return helper(l->left, r->right) && helper(l->right, r->left);
        else return false;
    }
};

2、层次遍历
class Solution {
public:
    bool isSymmetrical(TreeNode* pRoot)
    {
        if(!pRoot) return true;
        queue<TreeNode*>q;//层次遍历，率先想到用队列
        q.push(pRoot);
        vector<TreeNode*>array;//vector要存节点，而不能存值
        while(!q.empty()){
            int n=q.size();
            for(int i=0;i<n;i++){
                TreeNode*tmp=q.front();
                q.pop();
                array.push_back(tmp);
                if(tmp){//常用的层次遍历要判断左右子树是否存在，与此处不同
                    q.push(tmp->left);
                    q.push(tmp->right);
                }
            }
            int size=array.size();
            int i=0,j=size-1;
            while(i<j){
                if(array[i]&&array[j]&&array[i]->val==array[j]->val||!array[i]&&!array[j]){i++;j--;}
                else return false;
            }
            vector<TreeNode*>().swap(array);//清空并释放内存
        }
        return true;
    }
};
