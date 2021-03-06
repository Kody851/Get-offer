题目描述
输入一棵二叉搜索树，将该二叉搜索树转换成一个排序的双向链表。要求不能创建任何新的结点，只能调整树中结点指针的指向。
class Solution {
public:
    TreeNode* Convert(TreeNode* pRootOfTree)
    {
        if(!pRootOfTree) return NULL;
        TreeNode*pre=NULL;
        helper(pRootOfTree,pre);
        /*获取链表的头，即树的最左边节点*/
        TreeNode*res=pRootOfTree;
        while(res->left) res=res->left;
        return res;
    }
    void helper(TreeNode* pRootOfTree, TreeNode*&pre){//pre的值需要更改，使用&
      /*完成双向链表的生成，箭头由左至右为升序，由右至左为降序。根节点仍不会变*/
        if(!pRootOfTree) return;
        helper(pRootOfTree->left, pre);//中序遍历
        pRootOfTree->left=pre;
        if(pre) pre->right=pRootOfTree;
        pre=pRootOfTree;
        helper(pRootOfTree->right, pre);
    }
};

有时间检查一下以下思路：
class Solution {
public:
    TreeNode* Convert(TreeNode* pRootOfTree)
    {
        if(!pRootOfTree) return NULL;
        TreeNode*left=Convert(pRootOfTree->left);
        TreeNode*cur=left;
        while(cur->right) cur=cur->right;
        cur->right=pRootOfTree;
        pRootOfTree->left=cur;
        TreeNode*right=Convert(pRootOfTree->right);
        pRootOfTree->right=right;
        right->left=pRootOfTree;
        
        return left;
    }
};
