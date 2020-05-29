题目描述
给定一棵二叉搜索树，请找出其中的第k小的结点。例如， （5，3，7，2，4，6，8）    中，按结点数值大小顺序第三小结点的值为4。
中序遍历二叉搜索树，即是按从小到大排列。
自然想到：
class Solution {
public:
    TreeNode* KthNode(TreeNode* pRoot, int k)
    {
        if(!pRoot||k<=0) return NULL;
        vector<TreeNode*>node;
        helper(pRoot,node);
        if(k>node.size()) return NULL;//必须要判断
        return node[k-1];
    }
    void helper(TreeNode* pRoot, vector<TreeNode*>&node){
        if(!pRoot) return;
        helper(pRoot->left,node);
        node.push_back(pRoot);
        helper(pRoot->right,node);
    }
};
但是这样要全部遍历，最优解只需遍历到第K小的即可：
class Solution {//一边中序遍历，一边计数，之前的节点不用储存
public:
    int count=0;
    TreeNode* KthNode(TreeNode* pRoot,  int k)
    {
        if(pRoot){
            TreeNode*tmp=KthNode(pRoot->left,k);
            if(tmp) return tmp;//正向递归时，tmp一直为NULL；找到pRoot之后反向递归，tmp为真，不停向上递归
            if(++count==k) return pRoot;
            tmp=KthNode(pRoot->right,k);
            if(tmp) return tmp;//这里可以不判断if(tmp)，因为tmp为空时会到语句return NULL;效果相同
        }
        return NULL;
    }
};
剑指offer：
class Solution {
public:
    TreeNode* KthNode(TreeNode* pRoot, int k)
    {
        if(!pRoot||k<=0) return NULL;
        return KthNodeCore(pRoot,k);
        
    }
    TreeNode* KthNodeCore(TreeNode* pRoot, int &k){
        TreeNode*target=NULL;
        if(pRoot->left) target=KthNodeCore(pRoot->left,k);
        if(!target){
            if(k==1) target=pRoot;
            k--;
        }
        if(!target&&pRoot->right) target=KthNodeCore(pRoot->right,k);
        return target;
    }
};
改编：
class Solution {
public:
    int count=1;
    TreeNode* KthNode(TreeNode* pRoot, int k)
    {
        if(!pRoot||k<=0) return NULL;
        TreeNode*target=NULL;
        if(pRoot->left) target=KthNode(pRoot->left,k);
        if(!target){
            if(count==k) target=pRoot;
            count++;
        }
        if(!target&&pRoot->right) target=KthNode(pRoot->right,k);
        return target;
    }
};
190415:
class Solution {
public:
    TreeNode* KthNode(TreeNode* pRoot, int k)
    {
        if(!pRoot||k<=0) return NULL;
        int count=1;
        return KthNodeCore(pRoot,k,count);
    }

    TreeNode* KthNodeCore(TreeNode* pRoot, int k, int &count){
        TreeNode*res=NULL;
        if(pRoot->left) res=KthNodeCore(pRoot->left,k,count);
        if(res==NULL){
            if(count==k) res=pRoot;
            else count++;
        }
        if(res==NULL&&pRoot->right) res=KthNodeCore(pRoot->right,k,count);
        return res;//整个递归过程，要么返回NULL要么返回第k小的节点
    }
};
